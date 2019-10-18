#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
public:
	enum class TokenType : std::string
	{

		IMPORT				:		"IMPORT",			// #import module
		DEFINE				:		"DEFINE",			// #define target Pytorch
		
		IDENTIFIER			:		"IDENTIFIER", 		// identifier = | {

		LENOF				:		"LENOF",			// len(layer1)
		NEWLINE				:		"NEWLINE",				// '\n'
		QUOTE				:		"QUOTE",			// '\"'
		PLUS				:		"PLUS",				// '+'
		ASSIGN				:		"ASSIGN",			// '='

		STR_LITERAL			:		"STR_LITERAL",		// names
		INT_LITERAL			:		"INT_LITERAL",		// integer values
		BOOL_LITERAL		:		"BOOL_LITERAL",		// True/False 1/0

		LBRA				:		"LBRA",				// '{'
		RBRA				:		"RBRA",				// '}'
		LPAR				:		"LPAR",				// '('
		RPAR				:		"RPAR",				// ')'
		LSBR				:		"LSBR",				// '['
		RSBR				:		"RSBR",				// ']'

		END					:		"END",				// EOF
		INVALID				:		"INVALID"			// Unk token
	};

	Token() = delete;
	Token(TokenType t, std::string d = "") : token(t), data(d) {}
	~Token() = default;

	const TokenType &getToken() const{
		return token;
	}

private:
	TokenType token;
	std::string data;
};

#endif
