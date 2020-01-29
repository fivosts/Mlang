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

	// TODO  Convert them to pure virtuals once name analyzer and type checker have their prototypes
	virtual void visit(const std::unique_ptr<Model> & /*m*/) {}
	virtual void visit(const std::unique_ptr<Import> & /*i*/) {}
	virtual void visit(const std::unique_ptr<Attribute> & /*s*/) {}
	virtual void visit(const std::unique_ptr<Layer> & /*l*/) {}
	virtual void visit(const std::unique_ptr<ParamBlock> & /*pb*/) {}
	virtual void visit(const std::unique_ptr<HyperparamBlock> & /*hpb*/) {}
	virtual void visit(const std::unique_ptr<LayerParams> & /*lp*/) {}
	virtual void visit(const std::unique_ptr<HyperParams> & /*hp*/) {}
	virtual void visit(const std::unique_ptr<BinExpr> & /*be*/) {}
	virtual void visit(const std::unique_ptr<LengthOf> & /*lo*/) {}
	virtual void visit(std::string /*s*/) {}
	virtual void visit(int /*i*/) {}

// protected:
// 	const std::unique_ptr<Model> model = NULL;
};
