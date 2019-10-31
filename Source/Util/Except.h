#pragma once

#include <stdexcept>

class CompExcept : public std::runtime_error
{
public:
    CompExcept(std::string what) : runtime_error(what) {}
};

template<typename T = const char*>
std::string joinWhSpace(const char* &&cstr)
{
    return std::string(cstr);
}

template<typename T = int>
std::string joinWhSpace(int &&istr)
{
    return std::to_string(istr);
}

template <typename T>
std::string joinWhSpace(T&& str)
{
    return str;
}

template <typename T, typename... U>
std::string joinWhSpace(T&& str, U&& ...nstr)
{
    return joinWhSpace(str) + joinWhSpace(" ") + joinWhSpace(nstr...);
}

