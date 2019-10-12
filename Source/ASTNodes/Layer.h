#ifndef LAYER_H
#define LAYER_H

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
	LSTM() = default;
	~LSTM() override = default;

private:
	ParamBlock* pblock{NULL};
	HyperparamBlock* hblock{NULL};
};

class MLP : public Layer
{
public:
	MLP() = default;
	~MLP() override = default;

private:
	ParamBlock* pblock{NULL};
	HyperparamBlock* hblock{NULL};
};

class Sigmoid : public Layer
{
public:
	Sigmoid() = default;
	~Sigmoid() override = default;

private:
	ParamBlock* pblock{NULL};
};

#endif