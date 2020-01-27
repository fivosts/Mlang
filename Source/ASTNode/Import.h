#pragma once

#include "ASTNode.h"

#include <string>

typedef std::string importPath;

class Import : ASTNode
{
public:
	Import() = delete;
	Import(importPath ip) : path(ip) {}
	virtual ~Import() override = default;

	void accept(ASTVisitor *v) override
	{
		v->visit(path);
	}

private:
	importPath path;
};
