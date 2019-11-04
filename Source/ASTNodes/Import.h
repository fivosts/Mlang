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

private:
	importPath path;
};
