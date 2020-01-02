#pragma once

#include "Params.h"
#include "Expression.h"
#include "LengthOf.h"

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
	InputSize(std::unique_ptr<LengthOf> lo) : llength(std::move(lo)) {}
	~InputSize() override = default;

private:
	int inSize;
	std::unique_ptr<LengthOf> llength;
};

class OutputTimestep : public LSTMParams
{
public:
	OutputTimestep() = delete;
	OutputTimestep(int os) : outStep(os) {}
	~OutputTimestep() override = default;

private:
	int outStep;
};

class HiddenSize : public LSTMParams
{
public:
	HiddenSize() = delete;
	HiddenSize(int hs) : hSize(hs) {}
	~HiddenSize() override = default;

private:
	int hSize;
};

class NumLayers : public LSTMParams
{
public:
	NumLayers() = delete;
	NumLayers(int nl) : nLayers(nl) {}
	~NumLayers() override = default;

private:
	int nLayers;
};

class InFeatures : public MLParams
{
public:
	InFeatures() = delete;
	InFeatures(int i) : inF(is) {}
	InFeatures(std::unique_ptr<LengthOf> lo) : llength(std::move(lo)) {}
	~InFeatures() override = default;

private:
	int inF;
	std::unique_ptr<LengthOf> llength;
};

class OutFeatures : public MLParams
{
public:
	OutFeatures() = delete;
	OutFeatures(int of) : outFeat(of) {}
	~OutFeatures() override = default;

private:
	int outFeat;
};
