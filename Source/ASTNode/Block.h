#pragma once

#include "Params.h"

#include <unordered_set>
#include <memory>

template<typename T>
using setParams = std::unordered_set<std::unique_ptr<T>>;

class ParamBlock : public ASTNode
{
public:
	ParamBlock() = delete;
	ParamBlock(setParams<LayerParams> lp) : lparams(std::move(lp)) {}
	~ParamBlock() = default;

	void accept(ASTVisitor &v) override
	{
		for (auto &lp : lparams)
			v.visit(std::move(lp));
	}

private:
	setParams<LayerParams> lparams;
};

class HyperparamBlock : public ASTNode
{
public:
	HyperparamBlock() = delete;
	HyperparamBlock(setParams<HyperParams> hp) : hparams(std::move(hp)) {}
	~HyperparamBlock() = default;
	
	void accept(ASTVisitor &v) override
	{
		for (auto &hp : hparams)
			v.visit(std::move(hp));
	}

private:
	setParams<HyperParams> hparams;
};
