#pragma once

#include "Token.h"

#include <stdexcept>

class CompExcept : public std::runtime_error
{
public:
    CompExcept() = delete;
    CompExcept(std::string what) : runtime_error(what) {}
};

std::string tokenToStr(Token::TokenType tt, std::string dt = "");

template<typename T = const char*>
static std::string joinWhSpace(const char* &&cstr)
{
    return std::string(cstr);
}

template<typename T = int>
static std::string joinWhSpace(int &&istr)
{
    return std::to_string(istr);
}

template <typename T>
static std::string joinWhSpace(T&& str)
{
    return str;
}

template <typename T, typename... U>
std::string joinWhSpace(T&& str, U&& ...nstr)
{
    return joinWhSpace(str) + joinWhSpace(" ") + joinWhSpace(nstr...);
}

