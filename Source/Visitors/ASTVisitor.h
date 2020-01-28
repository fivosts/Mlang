#pragma once

#include "ASTNode.h"
#include "LayerProperties.h"
#include "Expression.h"
#include "Model.h"
#include "Block.h"

#include <memory>

class ASTVisitor
{
public:
	ASTVisitor() = default;
	virtual ~ASTVisitor() = 0;

	virtual void visit(std::string /*s*/){

	}

	virtual void visit(int /*s*/){

	}

	virtual void visit(const std::unique_ptr<LayerParams> &lp){
		(void)lp;
		lp->accept(this);
	}

	virtual void visit(const std::unique_ptr<HyperParams> &hp){
		(void)hp;
	}

	virtual void visit(const std::unique_ptr<BinExpr> &lp){
		(void)lp;
	}

	virtual void visit(const std::unique_ptr<LengthOf> & /*lo*/) {}

	virtual void visit(const std::unique_ptr<Layer> &lp){
		(void)lp;
	}

	virtual void visit(const std::unique_ptr<Model> &lp){
		(void)lp;
	}

	virtual void visit(const std::unique_ptr<ParamBlock> &lp){
		(void)lp;
	}

	virtual void visit(const std::unique_ptr<HyperparamBlock> &lp){
		(void)lp;
	}

	virtual void visit(const std::unique_ptr<Import> &lp){
		lp->accept(this);
	}

	virtual void visit(const std::unique_ptr<Attribute> &lp){
		(void)lp;
	}

// protected:
// 	const std::unique_ptr<Model> model = NULL;
};
