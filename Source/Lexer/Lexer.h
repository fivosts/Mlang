#pragma once

#include "Scanner.h"
#include "Token.h"

#include <memory>

class Lexer
{
public:
	Lexer() = delete;
	Lexer(std::unique_ptr<Scanner> c) : sc(std::move(c)){}
	~Lexer() = default;
	const Token nextToken();

private:
	std::shared_ptr<Scanner> sc;
};
