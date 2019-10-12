#ifndef LAYER_H
#define LAYER_H

#include "Block.h"

class Layers : public ASTNode
{
public:
	Layers() = delete;
	virtual ~Layers() = 0;
};

class LSTM : public Layers
{
public:
	LSTM() = default;
	~LSTM() override = default;

private:
	ParamBlock* pblock{NULL};
	HyperparamBlock* hblock{NULL};
};

class MLP : public Layers
{
public:
	MLP() = default;
	~MLP() override = default;

private:
	ParamBlock* pblock{NULL};
	HyperparamBlock* hblock{NULL};
};

class Sigmoid : public Layers
{
public:
	Sigmoid() = default;
	~Sigmoid() override = default;

private:
	ParamBlock* pblock{NULL};
};

#endif