#ifndef LEXER_H
#define LEXER_H

#include "Scanner.h"
#include "Token.h"

class Lexer
{
public:
	Lexer(Scanner *c) : sc(c){}
	~Lexer() = default;
	const Token nextToken();

private:
	Scanner *sc;
};

#endif