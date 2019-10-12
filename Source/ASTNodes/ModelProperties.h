#ifndef MODELPROPERTIES_H
#define MODELPROPERTIES_H

#include "Attribute.h"

#include <string>
#include <unordered_set>

class NetworkName : public Attribute
{
public:
	NetworkName() = default;
	~NetworkName() override = default;

private:
	std::string name;
};

class Backend : public Attribute
{
public:
	Backend() = default;
	~Backend() override = default;

private:
	std::string bend;
};

class Target : public Attribute
{
public:
	Target() = default;
	~Target() override = default;

private:
	std::string target;
};

class CUDA : public Attribute
{
public:
	CUDA() = default;
	~CUDA() override = default;

private:
	bool cuda;
};

class InpTensors : public Attribute
{
public:
	InpTensors() = default;
	~InpTensors() override = default;

private:
	std::unordered_set<std::string> inTens;
};

class OutTensors : public Attribute
{
public:
	OutTensors() = default;
	~OutTensors() override = default;

private:
	std::unordered_set<std::string> outTens;
};

#endif