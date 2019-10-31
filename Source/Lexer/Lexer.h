#pragma once

#include "Scanner.h"
#include "Token.h"
#include "Except.h"

#include <memory>

class Lexer
{
public:
	Lexer() = delete;
	Lexer(std::unique_ptr<Scanner> &&c) : sc(std::move(c)){}
	~Lexer() = default;

	// TODO move this to private section
	const Token nextToken();

	const Token safeNextToken()
	{
		Token t = nextToken();
		if (t.getToken() == Token::TokenType::INVALID)
		{
			throw CompExcept(joinWhSpace(t.getStrPos(), "Use of undeclared identifier", t.getData()));
		}		
		return t;
	}
	
private:
	bool isDigit(char&& c)
	{
		return (c <= (char)('9') 
				&& c >= (char)('0'));
	}

	bool isLetter(char&& c)
	{
		return ((c >= (char)'A' 
				&& c <= (char)'Z')
				|| 
				(c >= (char)'a' 
				&& c <= (char)'z'));
	}

private:
	std::shared_ptr<Scanner> sc;
};
