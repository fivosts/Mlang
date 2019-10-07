#ifndef MODEL_H
#define MODEL_H

#include "ASTNode.h"
#include "Import.h"
#include "Attribute.h"

#include <vector>

using namespace std;

class Model : ASTNode
{
public:
	Model() = default;
	~Model() override = default;

private:
	vector<Import> imp;
	vector<Attribute> attr;
	// vector<Layer> lr;
};

#endif