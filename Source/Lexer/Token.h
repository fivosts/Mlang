#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
public:
	enum class TokenType
	{

		IMPORT,			// #import module
		DEFINE,			// #define target Pytorch
		
		IDENTIFIER, 	// identifier (see grammar)

		NEWLINE,		// '\n'
		PLUS,			// '+'
		ASSIGN,			// '='

		STR_LITERAL,	// "([a-z] | [A-Z] | [0-9] | '_')*"
		INT_LITERAL,	// ([0-9])*
		BOOL_LITERAL,	// True/False true/false 1/0

		LBRA,			// '{'
		RBRA,			// '}'
		LPAR,			// '('
		RPAR,			// ')'
		LSBR,			// '['
		RSBR,			// ']'

		END,			// EOF
		INVALID			// Unk token
	};

    using Position = std::pair<int, int>;

	Token() = delete;
	Token(TokenType t, Position p, std::string d = "") : token(t), pos(p), data(d) {}
	~Token() = default;

	const TokenType &getToken() const{
		return token;
	}

private:
	TokenType token;
	std::string data;
	Position pos;
};

#endif
