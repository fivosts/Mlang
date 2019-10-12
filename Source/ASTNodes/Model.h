#ifndef MODEL_H
#define MODEL_H

#include "ASTNode.h"
#include "Import.h"
#include "Attribute.h"
#include "Layer.h"

#include <vector>
#include <unordered_set>

class Model : ASTNode
{
public:
	Model() = default;
	~Model() override = default;

private:
	std::unordered_set<Import*> imp;
	std::unordered_set<Attribute*> attr;
	std::unordered_set<Layer*> lr;
};

#endif
