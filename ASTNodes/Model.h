#ifndef MODEL_H
#define MODEL_H

#include "ASTNode.h"
#include "Import.h"
#include "Attribute.h"

#include <vector>

class Model : ASTNode
{
public:
	Model() = default;
	~Model() override = default;

private:
	std::vector<Import> imp;
	std::vector<Attribute> attr;
	// vector<Layer> lr;
};

#endif