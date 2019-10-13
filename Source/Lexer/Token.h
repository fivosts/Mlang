#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
public:
	enum class TokenType{

		IMPORT,			// #import module
		DEFINE,			// #define target Pytorch
		
		IDENTIFIER, 	// identifier = | {

		LENOF,			// len(layer1)
		ENDL,			// '\n'
		QUOTE,			// '\"'

		STR_LITERAL,	// names
		INT_LITERAL,	// integer values
		BOOL_LITERAL,	// True/False 1/0

		LBRA,			// '{'
		RBRA,			// '}'
		PLUS,			// '+'
		LPAR,			// '('
		RPAR,			// ')'
		LSBR,			// '['
		RSBR,			// ']'

		EOF,			// End of file
		INVALID			// Unk token
	}
};

#endif
