#pragma once

#include "Lexer.h"
#include "Model.h"

#include <memory>

class Parser
{	
public:
	Parser(Lexer l) : lex(l) {}
	~Parser() = default;

private:

	template <typename T>
	inline bool accept(T&& ct)
	{
		return (tokPend ? *tokPend == ct 
						: [this](){
						  *tokPend = lex.nextToken();
						  return *tokPend;}() == ct);
	}

	template <typename T, typename... U>
	inline bool accept(T&& ct, U&& ...rt)
	{
		return accept(ct) && accept(std::forward(rt...));
	}

	template <typename T>
	inline bool expect(T&& ct)
	{
		bool ret = accept(ct);
		tokPend = NULL;
		return ret;
	}

	template <typename T, typename... U>
	inline bool expect(T&& ct, U&& ...rt)
	{
		return expect(ct) && expect(std::forward(rt...));
	}

public:
	// encapsulate parseModel into a try catch for lexer errors
	std::shared_ptr<Model> parse() { return parseModel(); }

private:
	Lexer lex;
	std::unique_ptr<Token> tokPend = NULL;

private:
	/***** Recursive descent parsing functions  *****/
	std::unique_ptr<Model> parseModel();
	std::unique_ptr<Import> parseImport();
	std::unique_ptr<Attribute> parseAttribute();
	std::unique_ptr<Layer> parseLayer();
};