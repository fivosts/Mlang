#include "Lexer.h"

const Token Lexer::nextToken()
{

	using Token::TokenType = TType;

	const char current = sc->nextChar();

	if (current == ' '){
		return Lexer::nextToken();
	}
	// #import and #define 
	else if (current == '#')
	{
		current = sc->nextChar();
		if (current == 'i')
		{

		}else if (current == 'd')
		{

		}
	}
	// Identifiers
	else if (current == 'b') 
	{

	}else if (current == 'c')
	{

	}else if (current == 'h')
	{

	}else if (current == 'i')
	{

	}else if (current == 'L')
	{

	}else if (current == 'l')
	{

	}else if (current == 'M')
	{

	}else if (current == 'n')
	{

	}else if (current == 'o')
	{

	}else if (current == 'S')
	{

	}
	// NEWLINE, QUOTE, Special characters \\ \t \b \r etc.
	else if (current == '\\')
	{

	}
	// PLUS
	else if (current == '+')
	{
		return Token(Token::TokenType::::PLUS);
	}
	// ASSIGN
	else if (current == '=')
	{
		return Token(Token::TokenType::ASSIGN);
	}
	// STRING Literals
	else if (current == '\"')
	{

	}
	// INT Literals
	else if (current <= (char)('9') && current >= (char)('0'))
	{

	}
	// BOOL Literals
	else if (current == 'T' || current == 't')
	{
		current = sc->nextChar();
		if (current == 'r')
		{
			current = sc->nextChar();
			if (current == 'u')
			{
				current = sc->nextChar();
				if (current == 'e')
				{
					return Token(Token::TokenType::BOOL_LITERAL, "True");
				}
			}
		}
	}
	else if (current == 'F' || current == 'f')
	{
		current = sc->nextChar();
		if (current == 'a')
		{
			current = sc->nextChar();
			if(current == 'l')
			{
				current = sc->nextChar();
				if (current == 's')
				{
					current = sc->nextChar();
					if (current == 'e')
					{
						return Token(Token::TokenType::BOOL_LITERAL, "False");
					}
				}
			}
		}

	}
	// LBRA, RBRA, LPAR, RPAR, LSBR, RSBR Tokens
	else if (current == '{')
	{
		return Token(Token::TokenType::LBRA);
	}
	else if (current == '}')
	{
		return Token(Token::TokenType::RBRA);
	}
	else if (current == '(')
	{
		return Token(Token::TokenType::LPAR);
	}
	else if (current == ')')
	{
		return Token(Token::TokenType::RPAR);
	}
	else if (current == '[')
	{
		return Token(Token::TokenType::LSBR);
	}
	else if (current == ']')
	{
		return Token(Token::TokenType::RSBR);
	}
	else if (current == EOF)
	{
		return Token(Token::TokenType::END);
	}
	// INVALID Token if not recognized.
	else{
		return Token(Token::TokenType::INVALID);
	}

}
