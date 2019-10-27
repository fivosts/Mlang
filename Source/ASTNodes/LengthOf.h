#pragma once

#include <string>

class LengthOf : public ASTNode
{
public:
	LengthOf() = default;
	~LengthOf() = default;

private:
	std::string layer;
};
