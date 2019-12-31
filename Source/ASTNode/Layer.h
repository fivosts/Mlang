#pragma once

#include "ASTNode.h"
#include "Block.h"

#include <memory>

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
	LSTM(std::unique_ptr<ParamBlock> pb,
		std::unique_ptr<HyperparamBlock> hb) : pblock(std::move(pb)), 
											   hblock(std::move(hb)) {}
	~LSTM() override = default;

private:
	std::unique_ptr<ParamBlock> pblock;
	std::unique_ptr<HyperparamBlock> hblock;
};

class MLP : public Layer
{
public:
	MLP() = delete;
	MLP(std::unique_ptr<ParamBlock> pb, 
		std::unique_ptr<HyperparamBlock> hb) : pblock(std::move(pb)), 
											hblock(std::move(hb)) {}
	~MLP() override = default;

private:
	std::unique_ptr<ParamBlock> pblock;
	std::unique_ptr<HyperparamBlock> hblock;
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
