#include "Lexer.h"
#include "Util.h"

#ifdef LEXDBG
std::unordered_map<Token::TokenType, std::string> Token::tokenMap = {
	FOR_TOKENTYPES(TOKEN_MAP)
};
#endif

const Token Lexer::nextToken()
{

	// using Token::TokenType = TokenType;
    using Position = std::pair<int, int>;

	char current = sc->nextChar();
	Position cpos = sc->getCurrentPosition();

	if (current == ' ' || current == '\t'){
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
			return Token(Token::TokenType::IMPORT, cpos);
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
			return Token(Token::TokenType::DEFINE, cpos);
		}}}}}}
	}
	// Identifiers and BOOL literals
	else if (isLetter(std::move(current)))
	{
		std::string id = "";
		id += current;
		char next = sc->peekChar();

		while(isLetter(std::move(next)) 
			|| isDigit(std::move(next)) 
			|| next == '_')
		{
			current = sc->nextChar();
			next = sc->peekChar();
			id += current;
		}
		if (id == "True" || id == "true")
		{
			return Token(Token::TokenType::BOOL_LITERAL, cpos, "True");
		}
		else if (id == "False" || id == "false")
		{
			return Token(Token::TokenType::BOOL_LITERAL, cpos, "False");
		}
		else
		{
			return Token(Token::TokenType::IDENTIFIER, cpos, id);
		}
	}
	// NEWLINE, Special characters \\ \t \b \r etc.
	else if (current == '\n')
	{
		return Token(Token::TokenType::NEWLINE, cpos);
	}
	// PLUS
	else if (current == '+')
	{
		return Token(Token::TokenType::PLUS, cpos);
	}
	// MINUS
	else if (current == '-')
	{
		return Token(Token::TokenType::MINUS, cpos);
	}
	// ASSIGN
	else if (current == '=')
	{
		return Token(Token::TokenType::ASSIGN, cpos);
	}
	// COMMA
	else if (current == ',')
	{
		return Token(Token::TokenType::COMMA, cpos);
	}
	// STRING Literals
	else if (current == '\"')
	{
		std::string strID = "";
		char next = sc->peekChar();
		while (next != '\"')
		{
			// Special characters and whitespaces
			// in STR are not allowed.
			if (next == '\'' || next == '\\' || next == ' '
			 || next == '\t' || next == '\b' || next == EOF
			 || next == '\0' || next == '\n')
			{
				strID += current;
				return Token(Token::TokenType::INVALID, cpos, strID);
			}
			else
			{
				current = sc->nextChar();
				next = sc->peekChar();
				strID += current;
			}
		}
		current = sc->nextChar();
		return Token(Token::TokenType::STR_LITERAL, cpos, strID);
	}
	// INT Literals
	else if (isDigit(std::move(current)))
	{
		std::string intID = "";
		intID += current;
		while (isDigit(sc->peekChar()))
		{
			current = sc->nextChar();
			intID += current;
		}
		return Token(Token::TokenType::INT_LITERAL, cpos);
	}
	// LBRA, RBRA, LPAR, RPAR, LSBR, RSBR Tokens
	else if (current == '{')
	{
		return Token(Token::TokenType::LBRA, cpos);
	}
	else if (current == '}')
	{
		return Token(Token::TokenType::RBRA, cpos);
	}
	else if (current == '(')
	{
		return Token(Token::TokenType::LPAR, cpos);
	}
	else if (current == ')')
	{
		return Token(Token::TokenType::RPAR, cpos);
	}
	else if (current == '[')
	{
		return Token(Token::TokenType::LSBR, cpos);
	}
	else if (current == ']')
	{
		return Token(Token::TokenType::RSBR, cpos);
	}
	// End-Of-File token
	else if (current == EOF)
	{
		return Token(Token::TokenType::END, cpos);
	}
	// INVALID Token if not recognized.
	// else{
	// 	// Throw an error here
	// 	return Token(Token::TokenType::INVALID, cpos, current);
	// }
	return Token(Token::TokenType::INVALID, cpos, current);
}
