#pragma once

#include "Attribute.h"

#include <string>
#include <unordered_set>

class NetworkName : public Attribute, public Identifier
{
public:
	NetworkName() = delete;
	NetworkName(std::string n) : name(n) {}
	~NetworkName() override = default;

private:
	std::string name;
};

class Backend : public Attribute, public Identifier
{
public:
	Backend() = delete;
	Backend(std::string b) : bend(b) {} 
	~Backend() override = default;

private:
	std::string bend;
};

class Target : public Attribute, public Identifier
{
public:
	Target() = delete;
	Target(std::string t) : target(t) {}
	~Target() override = default;

private:
	std::string target;
};

class CUDA : public Attribute, public Identifier
{
public:
	CUDA() = delete;
	CUDA(bool c) : cuda(c) {}
	~CUDA() override = default;

private:
	bool cuda;
};

class InpTensors : public Attribute, public Identifier
{
public:
	InpTensors() = delete;
	InpTensors(std::unordered_set<std::string> iT) : inTens(iT) {}
	~InpTensors() override = default;

private:
	std::unordered_set<std::string> inTens;
};

class OutTensors : public Attribute, public Identifier
{
public:
	OutTensors() = delete;
	OutTensors(std::unordered_set<std::string> oT) : outTens(oT) {}
	~OutTensors() override = default;

private:
	std::unordered_set<std::string> outTens;
};
