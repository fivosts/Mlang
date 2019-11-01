#pragma once

#include "ASTNode.h"

#include <string>

typedef std::string importPath;

class Import : ASTNode
{
public:
	Import() = default;
	virtual ~Import() override = default;

private:
	importPath path;
};
