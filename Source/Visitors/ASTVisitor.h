#pragma once

#include "ASTNode.h"


class ASTVisitor
{
public:
	ASTVisitor() = default;
	virtual ~ASTVisitor() = 0;

	virtual void visit(std::string /*s*/){}
	virtual void visit(std::unique_ptr<LayerParams> &&lp){
		(void)lp;
	}
	virtual void visit(std::shared_ptr<BinExpr> &&lp){
		(void)lp;
	}

	virtual void visit(std::shared_ptr<Layer> &&lp){
		(void)lp;
	}

	virtual void visit(std::unique_ptr<Model> &&lp){
		(void)lp;
	}

	virtual void visit(std::unique_ptr<ParamBlock> &&lp){
		(void)lp;
	}

	virtual void visit(std::unique_ptr<HyperparamBlock> &&lp){
		(void)lp;
	}

	virtual void visit(std::shared_ptr<Import> &&lp){
		lp->accept(this);
	}

	virtual void visit(std::unique_ptr<Attribute> &&lp){
		(void)lp;
	}

protected:
	std::shared_ptr<Model> model = NULL;
};
