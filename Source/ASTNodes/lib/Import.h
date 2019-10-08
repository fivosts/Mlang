#ifndef IMPORT_H
#define IMPORT_H

#include "ASTNode.h"

#include <string>

using namespace std;
typedef string importPath;

class Import : ASTNode
{
public:
	Import() = default;
	~Import() override = default;

private:
	importPath path;
};

#endif