#ifndef PARAMS_H
#define PARAMS_H

class LayerParams : public ASTNode
{
public:
	LayerParams() = delete;
	virtual ~LayerParams() = 0;
};

class HyperParams : public ASTNode
{
public:
	HyperParams() = delete;
	virtual ~HyperParams() = 0;
};

class LSTMParams : public HyperParams
{
public:
	LSTMParams() = delete;
	~LSTMParams() override = default;
};

class MLParams : public HyperParams
{
public:
	MLParams() = delete;
	~MLParams() override = default;
};

#endif