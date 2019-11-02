#pragma once

#include "Lexer.h"
#include "Model.h"

#include <memory>

class Parser
{	
public:
	Parser() = delete;
	Parser(std::unique_ptr<Lexer> &&l)
	{
		try
		{	lex = std::move(l);	}
		catch(CompExcept &ex)
		{	throw;				}
	}

	Parser(std::unique_ptr<Scanner> &&sc)
	{
		try
		{	lex = std::make_unique<Lexer>(std::move(sc));	}
		catch(CompExcept &ex)
		{	throw;				}
	}

	Parser(std::string fp)
	{
		try
		{	lex = std::make_unique<Lexer>(fp);	}
		catch(CompExcept &ex)
		{	throw;											}
	}
	
	~Parser()
	{
		lex = NULL;
		tokPend = NULL;
	}

private:

	template <typename T>
	inline bool accept(T&& ct)
	{
		return (tokPend ? *tokPend == ct 
						: [this](){
						  *tokPend = lex->safeNextToken();
						  return *tokPend;}() == ct);
	}

	// This function is broken unless you set a queuing system.
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

	// This function is broken unless you set a queuing system.
	// Comments:
	// 1) expect must return a token
	// 2) template deduced expect makes no sense. Which would you return ?
	// 3) expect must throw exception for parsing error should it not find the token
	template <typename T, typename... U>
	inline bool expect(T&& ct, U&& ...rt)
	{
		return expect(ct) && expect(std::forward(rt...));
	}

public:
	// encapsulate parseModel into a try catch for lexer errors
	std::shared_ptr<Model> safeParseModel()
	{
		try 						{	model = parseModel();
										return model;			}
		catch (CompExcept& ex)		{	throw;					}	
	}

private:
	/***** Recursive descent parsing functions  *****/
	std::unique_ptr<Model> parseModel();
	std::unordered_set<std::unique_ptr<Import>> parseImport();
	std::unordered_set<std::unique_ptr<Attribute>> parseAttribute();
	std::unordered_set<std::unique_ptr<Layer>> parseLayer();
	
private:
	std::unique_ptr<Lexer> lex = NULL;
	std::unique_ptr<Token> tokPend = NULL;
	std::shared_ptr<Model> model = NULL;
};