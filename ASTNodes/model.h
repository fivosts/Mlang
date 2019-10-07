#ifndef MODEL_H
#define MODEL_H

#include "Node.h"

#include <vector>

using namespace std;

class Model
{
public:
	Model() = default;
	~Model() = default;

private:
	vector<Import> imp;
	Attributes attr;
	vector<Layer> lr;
};

#endif