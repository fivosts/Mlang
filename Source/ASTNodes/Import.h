#pragma once

#include "ASTNode.h"

#include <string>

typedef std::string importPath;

class Import : ASTNode
{
public:
	Import() = default;
	~Import() override = default;

private:
	importPath path;
};
