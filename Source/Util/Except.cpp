#include "Except.h"

std::string tokenToStr(Token::TokenType tt, std::string dt)
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
			return "IDENTIFIER" + (dt != "" ? " " + dt : dt);
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
			return "STR_LITERAL" + (dt != "" ? " " + dt : dt);
		}
		case Token::TokenType::INT_LITERAL:
		{
			return "INT_LITERAL" + (dt != "" ? " " + dt : dt);
		}
		case Token::TokenType::BOOL_LITERAL:
		{
			return "BOOL_LITERAL" + (dt != "" ? " " + dt : dt);
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
			return "INVALID" + (dt != "" ? " " + dt : dt);
		}
	}
	throw CompExcept("TokenType not found!");
	return "";
}

const char* tokenToCChar(Token::TokenType tt, std::string dt)
{
	return tokenToStr(tt, dt).c_str();
}
