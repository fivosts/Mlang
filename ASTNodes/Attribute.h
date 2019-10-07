#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

class Attribute : ASTNode
{
public:
	Attribute() = delete;
	virtual ~Attribute() override = 0;

};

class MandatoryAttribute : Attribute
{
public:
	MandatoryAttribute() = default;
	~MandatoryAttribute() override = default;
};

#endif
