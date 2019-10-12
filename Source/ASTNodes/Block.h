#ifndef BLOCK_H
#define BLOCK_H

#include "Params.h"

#include <unordered_set>

class ParamBlock : public ASTNode
{
public:
	ParamBlock() = default;
	~ParamBlock() = default;

private:
	std::unordered_set<LayerParams*> lparams;
};

class HyperparamBlock : public ASTNode
{
public:
	HyperparamBlock() = default;
	~HyperparamBlock() = default;

private:
	std::unordered_set<HyperParams*> hparams;
};

#endif