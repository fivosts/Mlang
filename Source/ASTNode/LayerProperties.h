#pragma once

#include "Params.h"
#include "Expression.h"

#include <string>

class Input : public LayerParams
{
public:
	Input() = delete;
	Input(std::unique_ptr<BinExpr> bi) : inp(std::move(bi)) {}
	~Input() override = default;

private:
	std::unique_ptr<BinExpr> inp;
};

class Output : public LayerParams
{
public:
	Output() = delete;
	Output(std::string o) : outp(o) {} 
	~Output() override = default;

private:
	std::string outp;
};

class LayerName : public LayerParams
{
public:
	LayerName() = delete;
	LayerName(std::string n) : name(n) {}
	~LayerName() override = default;

private:
	std::string name;
};

class InputSize : public LSTMParams
{
public:
	InputSize() = delete;
	InputSize(int is) : inSize(is) {}
	~InputSize() override = default;

private:
	[[maybe_unused]] int inSize;
};

class OutputTimestep : public LSTMParams
{
public:
	OutputTimestep() = delete;
	OutputTimestep(int os) : outStep(os) {}
	~OutputTimestep() override = default;

private:
	[[maybe_unused]] int outStep;
};

class HiddenSize : public LSTMParams
{
public:
	HiddenSize() = delete;
	HiddenSize(int hs) : hSize(hs) {}
	~HiddenSize() override = default;

private:
	[[maybe_unused]] int hSize;
};

class NumLayers : public LSTMParams
{
public:
	NumLayers() = delete;
	NumLayers(int nl) : nLayers(nl) {}
	~NumLayers() override = default;

private:
	[[maybe_unused]] int nLayers;
};

template <class T>
class InFeatures : public MLParams
{
public:
	InFeatures() = delete;
	InFeatures(T inf) : inFeat(inf) {}
	~InFeatures() override = default;

private:
	T inFeat;
};

class OutFeatures : public MLParams
{
public:
	OutFeatures() = delete;
	OutFeatures(int of) : outFeat(of) {}
	~OutFeatures() override = default;

private:
	[[maybe_unused]] int outFeat;
};
