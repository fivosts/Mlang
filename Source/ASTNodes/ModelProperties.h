#ifndef MODELPROPERTIES_H
#define MODELPROPERTIES_H

#include "Attributes.h"

#include <string>
#include <unordered_set>

class NetworkName : public Attributes
{
public:
	NetworkName() = default;
	~NetworkName() override = default;

private:
	std::string name;
};

class Backend : public Attributes
{
public:
	Backend() = default;
	~Backend() override = default;

private:
	std::string bend;
};

class Target : public Attributes
{
public:
	Target() = default;
	~Target() override = default;

private:
	std::string target;
};

class CUDA : public Attributes
{
public:
	CUDA() = default;
	~CUDA() override = default;

private:
	bool cuda;
};

class InpTensors : public Attributes
{
public:
	InpTensors() = default;
	~InpTensors() override = default;

private:
	std::unordered_set<std::string> inTens;
};

class OutTensors : public Attributes
{
public:
	OutTensors() = default;
	~OutTensors() override = default;

private:
	std::unordered_set<std::string> outTens;
};

#endif