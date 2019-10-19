#include "Lexer.h"

const Token Lexer::nextToken()
{

	using Token::TokenType = TokenType;
    using Position = std::pair<int, int>;

	char current = sc->nextChar();
	Position cpos = sc->getCurrentPosition();

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
			return Token(TokenType::IMPORT, cpos);
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
			return Token(TokenType::DEFINE, cpos);
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
			return Token(TokenType::BOOL_LITERAL, cpos, "True");
		}
		else if (id == "False" || id == "false")
		{
			return Token(TokenType::BOOL_LITERAL, cpos, "False");
		}
		else
		{
			return Token(TokenType::IDENTIFIER, cpos, id);
		}
	}
	// NEWLINE, Special characters \\ \t \b \r etc.
	else if (current == '\n')
	{
		return Token(TokenType::NEWLINE, cpos);
	}
	// PLUS
	else if (current == '+')
	{
		return Token(TokenType::::PLUS, cpos);
	}
	// ASSIGN
	else if (current == '=')
	{
		return Token(TokenType::ASSIGN, cpos);
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
				return Token(TokenType::INVALID, cpos, current);
			}
			else
			{
				current = sc->nextChar();
				next = sc->peekChar();
				strID += current;
			}
		}
		return Token(TokenType::STR_LITERAL, cpos, strID);
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
		return Token(TokenType::INT_LITERAL, cpos);
	}
	// LBRA, RBRA, LPAR, RPAR, LSBR, RSBR Tokens
	else if (current == '{')
	{
		return Token(TokenType::LBRA, cpos);
	}
	else if (current == '}')
	{
		return Token(TokenType::RBRA, cpos);
	}
	else if (current == '(')
	{
		return Token(TokenType::LPAR, cpos);
	}
	else if (current == ')')
	{
		return Token(TokenType::RPAR, cpos);
	}
	else if (current == '[')
	{
		return Token(TokenType::LSBR, cpos);
	}
	else if (current == ']')
	{
		return Token(TokenType::RSBR, cpos);
	}
	// End-Of-File token
	else if (current == EOF)
	{
		return Token(TokenType::END, cpos);
	}
	// INVALID Token if not recognized.
	else{
		// Throw an error here
		return Token(TokenType::INVALID, cpos, current);
	}

}
