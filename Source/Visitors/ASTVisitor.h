#pragma once

class ASTVisitor
{
public:
	ASTVisitor() = default;
	virtual ~ASTVisitor() = 0;

protected:
	std::shared_ptr<Model> model = NULL;
};
