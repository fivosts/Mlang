#pragma once

#include "Params.h"

#include <unordered_set>

template<typename T>
using setParams = std::unordered_set<std::unique_ptr<T>>;

class ParamBlock : public ASTNode
{
public:
	ParamBlock() = delete;
	// ParamBlock(setParams<LayerParams> lp) : lparams(lp) {}
	~ParamBlock() = default;

private:
	//! TODO this unique ptr will nag about this line
	setParams<LayerParams> lparams;
};

class HyperparamBlock : public ASTNode, public Identifier
{
public:
	// TODO delete
	HyperparamBlock() = default;
	// HyperparamBlock(setParams<HyperParams> hp) : hparams(hp) {}
	~HyperparamBlock() = default;

private:
	//! TODO this unique ptr will nag about this line
	setParams<HyperParams> hparams;
};
