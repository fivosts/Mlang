#pragma once

#include "Identifier.h"
#include "Params.h"

#include <string>

class Input : public LayerParams, public Identifier
{
public:
	Input() = default;
	~Input() override { delete inp; }

private:
	BinExpr *inp;
};

class Output : public LayerParams, public Identifier
{
public:
	Output() = default;
	~Output() override = default;

private:
	std::string outp;
};

class LayerName : public LayerParams, public Identifier
{
public:
	LayerName() = default;
	~LayerName() override = default;

private:
	std::string name;
};

class InputSize : public LSTMParams, public Identifier
{
public:
	InputSize() = default;
	~InputSize() override = default;

private:
	int inSize;
};

class OutputTimestep : public LSTMParams, public Identifier
{
public:
	OutputTimestep() = default;
	~OutputTimestep() override = default;

private:
	int outStep;
};

class HiddenSize : public LSTMParams, public Identifier
{
public:
	HiddenSize() = default;
	~HiddenSize() override = default;

private:
	int hSize;
};

class NumLayers : public LSTMParams, public Identifier
{
public:
	NumLayers() = default;
	~NumLayers() override = default;

private:
	int nLayers;
};

template <class T>
class InFeatures : public MLParams, public Identifier
{
public:
	InFeatures() = default;
	~InFeatures() override = default;

private:
	T inFeat;
};

class OutFeatures : public MLParams, public Identifier
{
public:
	OutFeatures() = default;
	~OutFeatures() override = default;

private:
	int outFeat;
};
