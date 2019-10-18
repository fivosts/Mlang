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

	}
	// ASSIGN
	else if (current == '=')
	{

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

	}
	else if (current == 'F' || current == 'f')
	{

	}
	// LBRA, RBRA, LPAR, RPAR, LSBR, RSBR
	else if (current == '{')
	{

	}else if (current == '}')
	{

	}else if (current == '(')
	{

	}else if (current == ')')
	{

	}else if (current == '[')
	{

	}else if (current == ']')
	{

	}else if (current == EOF)
	{
		return Token(Token::TokenType::END);
	}
	// INVALID Token if not recognized.
	else{
		return Token(Token::TokenType::INVALID);
	}

}
