#pragma once

#include "ASTNode.h"
#include "Block.h"

class Layer : public ASTNode
{
public:
	Layer() = default;
	virtual ~Layer() = 0;
};

class LSTM : public Layer
{
public:
	LSTM() = delete;
	LSTM(std::unique_ptr<ParamBlock> pb) : pblock(std::move(pb)) {}
	~LSTM() override { delete hblock; }

private:
	std::unique_ptr<ParamBlock> pblock;
	HyperparamBlock* hblock{NULL};
};

class MLP : public Layer
{
public:
	MLP() = delete;
	MLP(std::unique_ptr<ParamBlock> pb) : pblock(std::move(pb)) {}
	~MLP() override { delete hblock;}

private:
	std::unique_ptr<ParamBlock> pblock;
	HyperparamBlock* hblock{NULL};
};

class Sigmoid : public Layer
{
public:
	Sigmoid() = delete;
	Sigmoid(std::unique_ptr<ParamBlock> pb) : pblock(std::move(pb)) {}
	~Sigmoid() override = default;

private:
	std::unique_ptr<ParamBlock> pblock;
};
