#ifndef LAYER_PROPERTIES_H
#define LAYER_PROPERTIES_H

#include "Params.h"

#include <string>

class Input : public LayerParams
{
public:
	Input() = default;
	~Input() override { delete inp; }

private:
	BinExpr *inp;
};

class Output : public LayerParams
{
public:
	Output() = default;
	~Output() = default;

private:
	std::string outp;
};

class LayerName : public LayerParams
{
public:
	LayerName() = default;
	~LayerName() override = default;

private:
	std::string name;
};

class InputSize : public LSTMParams{
public:
	InputSize() = default;
	~InputSize() override = default;

private:
	int inSize;
};

class OutputTimestep : public LSTMParams{
public:
	OutputTimestep() = default;
	~OutputTimestep() override = default;

private:
	int outStep;
};

class HiddenSize : public LSTMParams{
public:
	HiddenSize() = default;
	~HiddenSize() override = default;

private:
	int hSize;
};

class NumLayers : public LSTMParams{
public:
	NumLayers() = default;
	~NumLayers() override = default;

private:
	int nLayers;
};

template <class T>
class InFeatures : public MLParams{
public:
	// InFeatures() = default;
	// ~InFeatures() override = default;

private:
	T inFeat;
};

class OutFeatures : public MLParams{
public:
	OutFeatures() = default;
	~OutFeatures() override = default;

private:
	int outFeat;
};

#endif