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
		current = sc->nextChar();
		if (current == 'm')
		{
		current = sc->nextChar();
		if (current == 'p')
		{
		current = sc->nextChar();
		if (current == 'o')
		{
		current = sc->nextChar();
		if (current == 'r')
		{
		current = sc->nextChar();
		if (current == 't')
		{
			return Token(Token::TokenType::IMPORT);
		}}}}}}
		
		else if (current == 'd')
		{
		current = sc->nextChar();
		if (current == 'e')
		{
		current = sc->nextChar();
		if (current == 'f')
		{
		current = sc->nextChar();
		if (current == 'i')
		{
		current = sc->nextChar();
		if (current == 'n')
		{
		current = sc->nextChar();
		if (current == 'e')
		{
			return Token(Token::TokenType::DEFINE);
		}}}}}}
	}
	// Identifiers and BOOL literals
	else if (isLetter(current))
	{
		std::string id = current;
		char next = sc->peekChar();
		while(isLetter(next) 
			|| isDigit(next) 
			|| next == '_')
		{
			current = sc->nextChar();
			next = sc->peekChar();
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
		std::string strID = "";
		char next = sc->peekChar();
		while (next != "\"")
		{
			// Special characters and whitespaces
			// in STR are not allowed.
			if (next == '\'' || next == '\\' || next == ' '
			 || next == '\t' || next == '\b'
			 || next == '\0' || next == '\n')
			{
				current = sc->nextChar();
				return Token(Token::TokenType::INVALID, current);
			}
			else
			{
				current = sc->nextChar();
				next = sc->peekChar();
				strID += current;
			}
		}
		return Token(Token::TokenType::STR_LITERAL, strID);
	}
	// INT Literals
	else if (isDigit(current))
	{
		std::string intID = current;
		while (isDigit(sc->peekChar()))
		{
			current = sc->nextChar();
			intId += current;
		}
		return Token(Token::TokenType::INT_LITERAL);
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
	// End-Of-File token
	else if (current == EOF)
	{
		return Token(Token::TokenType::END);
	}
	// INVALID Token if not recognized.
	else{
		// Throw an error here
		return Token(Token::TokenType::INVALID);
	}

}
