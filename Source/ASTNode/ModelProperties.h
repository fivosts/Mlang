#pragma once

#include "Attribute.h"

#include <string>
#include <unordered_set>

class NetworkName : public Attribute
{
public:
	NetworkName() = delete;
	NetworkName(std::string n) : name(n) {}
	~NetworkName() override = default;

	void accept(ASTVisitor* v) override;

	// TODO
	virtual void printData() override{
		std::cout << "I am definitely in the right place! My network name is: " << name << std::endl;
	}
private:
	std::string name;
};

class Backend : public Attribute
{
public:
	Backend() = delete;
	Backend(std::string b) : bend(b) {} 
	~Backend() override = default;

	void accept(ASTVisitor* v) override;

private:
	std::string bend;
};

class Target : public Attribute
{
public:
	Target() = delete;
	Target(std::string t) : target(t) {}
	~Target() override = default;

	void accept(ASTVisitor* v) override;

private:
	std::string target;
};

class CUDA : public Attribute
{
public:
	CUDA() = delete;
	CUDA(bool c) : cuda(c) {}
	~CUDA() override = default;

	void accept(ASTVisitor* v) override;

private:
	bool cuda;
};

class InpTensors : public Attribute
{
public:
	InpTensors() = delete;
	InpTensors(std::unordered_set<std::string> iT) : inTens(iT) {}
	~InpTensors() override = default;

	void accept(ASTVisitor* v) override;

private:
	std::unordered_set<std::string> inTens;
};

class OutTensors : public Attribute
{
public:
	OutTensors() = delete;
	OutTensors(std::unordered_set<std::string> oT) : outTens(oT) {}
	~OutTensors() override = default;

	void accept(ASTVisitor* v) override;

private:
	std::unordered_set<std::string> outTens;
};
