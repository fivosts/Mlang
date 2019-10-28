#ifndef LEXER_H
#define LEXER_H

#include "Scanner.h"
#include "Token.h"

#include <memory>

class Lexer
{
public:
	Lexer(std::unique_ptr<Scanner> sc) : sc(c){}
	~Lexer() {delete sc;}
	const Token nextToken();

private:
	std::unique_ptr<Scanner> sc;
};

#endif