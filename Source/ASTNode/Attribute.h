#pragma once

#include "ASTNode.h"
#include "Identifier.h"
#include <iostream>

class Attribute : public ASTNode, public Identifier
{
public:
	Attribute() = default;
	virtual ~Attribute() override = 0;

	virtual void printData() {
		std::cout << "This message is wrong\n";
	};
};
