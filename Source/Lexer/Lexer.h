#pragma once

#include "Scanner.h"
#include "Token.h"

#include <memory>

class Lexer
{
public:
	Lexer() = delete;
	Lexer(std::unique_ptr<Scanner> &&c) : sc(std::move(c)){}
	~Lexer() = default;
	const Token nextToken();
	const Token safeNextToken()
	{
		Token t = nextToken();
		if (t.getToken() == Token::TokenType::INVALID)
		{
			throw "Lexing error";
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
