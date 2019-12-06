#pragma once

#include "ASTNode.h"
#include <iostream>

class Attribute : public ASTNode
{
public:
	Attribute() = default;
	virtual ~Attribute() override = 0;

	virtual void printData() {
		std::cout << "This message is wrong\n";
	}
};
