#include "Except.h"

std::string tokenToStr(Token::TokenType tt)
{
	switch(tt)
	{
		case Token::TokenType::IMPORT:
		{
			return "IMPORT";
		}
		case Token::TokenType::DEFINE:
		{
			return "DEFINE";
		}
		case Token::TokenType::IDENTIFIER:
		{
			return "IDENTIFIER";
		}
		case Token::TokenType::NEWLINE:
		{
			return "NEWLINE";
		}
		case Token::TokenType::PLUS:
		{
			return "PLUS";
		}
		case Token::TokenType::MINUS:
		{
			return "MINUS";
		}
		case Token::TokenType::ASSIGN:
		{
			return "ASSIGN";
		}
		case Token::TokenType::COMMA:
		{
			return "COMMA";
		}
		case Token::TokenType::STR_LITERAL:
		{
			return "STR_LITERAL";
		}
		case Token::TokenType::INT_LITERAL:
		{
			return "INT_LITERAL";
		}
		case Token::TokenType::BOOL_LITERAL:
		{
			return "BOOL_LITERAL";
		}
		case Token::TokenType::LBRA:
		{
			return "LBRA";
		}
		case Token::TokenType::RBRA:
		{
			return "RBRA";
		}
		case Token::TokenType::LPAR:
		{
			return "LPAR";
		}
		case Token::TokenType::RPAR:
		{
			return "RPAR";
		}
		case Token::TokenType::LSBR:
		{
			return "LSBR";
		}
		case Token::TokenType::RSBR:
		{
			return "RSBR";
		}
		case Token::TokenType::END:
		{
			return "END_OF_FILE";
		}
		case Token::TokenType::INVALID:
		{
			return "INVALID";
		}
	}
	throw CompExcept("TokenType not found!");
	return "";
}