#pragma once

#include <string>

class LengthOf : public ASTNode
{
public:
	LengthOf() = delete;
	LengthOf(std::string l) : layer(l) {}
	~LengthOf() = default;

	void accept(ASTVisitor &v)
	{
		v.visit(layer);
	}

private:
	std::string layer;
};
