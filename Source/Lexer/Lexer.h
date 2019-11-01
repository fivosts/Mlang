#pragma once

#include "Scanner.h"
#include "Token.h"
#include "Except.h"

#include <memory>

class Lexer
{
public:
	Lexer() = delete;
	Lexer(std::unique_ptr<Scanner> &&c)
	{
		try
		{	sc = std::move(c);	}
		catch (CompExcept &ex)
		{	throw;				}
	}
	Lexer(std::string fp)
	{
		try
		{	sc = std::unique_ptr<Scanner>(new Scanner(fp));	}
		catch (CompExcept &ex)
		{	throw;											}
	}
	~Lexer()
	{
		sc = NULL;
	}
	// Lexer &operator= (Lexer &rhs)
	// {
	// 	sc = std::move(rhs.sc);
	// 	rhs.sc = NULL;
	// 	return this;
	// }

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
	std::unique_ptr<Scanner> sc;
};
