#include "Lexer.h"

const Token Lexer::nextToken()
{

	using Token::TokenType = TType;

	char current = sc->nextChar();

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
	else if (isLetter(current))
	{
		std::string id = current;
		char next = sc->peekChar();
		while(isLetter(next) 
			|| isDigit(next) 
			|| next == '_')
		{
			current = sc->nextChar();
			id += current;
		}
		if (id == "True" || id == "true")
		{
			return Token(Token::TokenType::BOOL_LITERAL, "True");
		}
		else if (id == "False" || id == "false")
		{
			return Token(Token::TokenType::BOOL_LITERAL, "False");
		}
		else
		{
			return Token(Token::TokenType::IDENTIFIER, id);
		}
	}
	// NEWLINE, Special characters \\ \t \b \r etc.
	else if (current == '\n')
	{
		return Token(Token::TokenType::NEWLINE);
	}
	// QUOTE
	else if (current == '\"')
	{
		return Token(Token::TokenType::QUOTE);
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
	else if (isDigit(current))
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
					// Trues as identifier causes an issue here
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
