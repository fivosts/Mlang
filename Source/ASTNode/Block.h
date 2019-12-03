#pragma once

#include "Params.h"

#include <unordered_set>

template<typename T>
using setParams<T> = std::unordered_set<std::unique_ptr<T>>;

class ParamBlock : public ASTNode
{
public:
	ParamBlock() = delete;
	ParamBlock(setParams<LayerParams> lp) : lparams(lp) {}
	~ParamBlock() = default;

private:
	setParams<LayerParams> lparams;
};

class HyperparamBlock : public ASTNode
{
public:
	HyperparamBlock() = delete;
	HyperparamBlock(setParams<HyperParams> hp) : hparams(hp) {}
	~HyperparamBlock() = default;

private:
	setParams<HyperParams> hparams;
};
