#pragma once

#include "ASTNode.h"
#include "Identifier.h"

class Attribute : public ASTNode, public Identifier
{
public:
	Attribute() = default;
	virtual ~Attribute() override = 0;

};
