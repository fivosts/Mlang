#pragma once

#include "Lexer.h"
#include "Model.h"

#include <queue>
#include <memory>

class Parser
{	
public:
	Parser(Lexer l) : lex(l) {}
	~Parser() = default;

	bool accept(Token &exp)
	{
		/*
			if queue is empty, invoke lambda to fetch one from lexer
			Otherwise load the queue
			!!! Don't do unnecessary reads from lexer.
			Lexer should be responsible to cut this off
		*/

		return (/*lambda*/ == exp ? true : false)
	}
	bool expect(Token &exp);

	std::shared_ptr<Model> parse() { return parseModel(); }

private:
	Lexer lex;
	std::queue<Token::TokenType> tokQu;

private:
	/***** Recursive descent parsing functions  *****/
	std::unique_ptr<Model> parseModel();
	std::unique_ptr<Import> parseImport();
	std::unique_ptr<Attribute> parseAttribute();
	std::unique_ptr<Layer> parseLayer();
};