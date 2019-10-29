#pragma once

#include "Lexer.h"
#include "Model.h"

#include <memory>

class Parser
{	
public:
	Parser(Lexer l) : lex(l) {}
	~Parser() = default;

	/*!!
		Queue is not needed atm because lookAhead is not in plans
		Otherwise, queue will be implemented, and accept will load i
		items in the queue, as instructed by lookAhead
	!!*/
	bool accept(Token &exp)
	{
		return (tokPend ? *tokPend == exp 
						: [this](){
						  *tokPend = lex.nextToken();
						  return *tokPend;}() == exp);
	}
	bool expect(Token &exp);

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