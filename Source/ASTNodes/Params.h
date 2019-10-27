#pragma once

class LayerParams : public ASTNode
{
public:
	LayerParams() = default;
	virtual ~LayerParams() = 0;
};

class HyperParams : public ASTNode
{
public:
	HyperParams() = default;
	virtual ~HyperParams() = 0;
};

class LSTMParams : public HyperParams
{
public:
	LSTMParams() = default;
	~LSTMParams() override = default;
};

class MLParams : public HyperParams
{
public:
	MLParams() = default;
	~MLParams() override = default;
};
