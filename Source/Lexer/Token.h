#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType
{

	IMPORT,			// #import module
	DEFINE,			// #define target Pytorch
	
	IDENTIFIER, 	// identifier = | {

	LENOF,			// len(layer1)
	ENDL,			// '\n'
	QUOTE,			// '\"'
	PLUS,			// '+'

	STR_LITERAL,	// names
	INT_LITERAL,	// integer values
	BOOL_LITERAL,	// True/False 1/0

	LBRA,			// '{'
	RBRA,			// '}'
	LPAR,			// '('
	RPAR,			// ')'
	LSBR,			// '['
	RSBR,			// ']'

	END,			// EOF
	INVALID			// Unk token
};

template<typename T>
class Token
{
public:
	Token() = default;
	~Token() = default;

private:
	T token;
};

#endif
