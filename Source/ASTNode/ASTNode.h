#pragma once

class ASTVisitor;

class ASTNode
{
public:
	ASTNode() = default;
	virtual ~ASTNode() = 0;
	virtual void accept(ASTVisitor *v) = 0;
};
