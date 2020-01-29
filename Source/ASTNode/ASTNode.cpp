#include "ASTNode.h"
#include "ASTVisitor.h"
#include "Attribute.h"
#include "Params.h"
#include "Layer.h"
#include "ModelProperties.h"

/*
Pure virtual Destructors
*/
ASTNode::~ASTNode() {}
Attribute::~Attribute() {}
LayerParams::~LayerParams() {}
HyperParams::~HyperParams() {}
Layer::~Layer() {}

/*
Visitor methods for AST Nodes
*/

//! Model
void Model::accept(ASTVisitor* v)
{
	for (auto &i : imp)
		v->visit(i);
	for (auto &a : attr)
		v->visit(a);
	for (auto &l : lr)
		v->visit(l);
}

//! Import
void Import::accept(ASTVisitor* v)
{
	v->visit(path);
}

//! Attribute
void NetworkName::accept(ASTVisitor* v)
{
	v->visit(name);
}

void Backend::accept(ASTVisitor* v)
{
	v->visit(bend);
}

void Target::accept(ASTVisitor* v)
{
	v->visit(target);
}

void CUDA::accept(ASTVisitor* v)
{
	v->visit(cuda);
}

void InpTensors::accept(ASTVisitor* v)
{
	for (auto &i : inTens)
		v->visit(i);
}

void OutTensors::accept(ASTVisitor* v)
{
	for (auto &i : outTens)
		v->visit(i);
}
//!

//! Layer
void LSTM::accept(ASTVisitor* v)
{
	v->visit(pblock);
	v->visit(hblock);
}

void MLP::accept(ASTVisitor* v)
{
	v->visit(pblock);
	v->visit(hblock);
}

void Sigmoid::accept(ASTVisitor* v)
{
	v->visit(pblock);
}
//!

//! Block
void ParamBlock::accept(ASTVisitor* v)
{
	for (auto &lp : lparams)
		v->visit(lp);
}

void HyperparamBlock::accept(ASTVisitor* v)
{
	for (auto &hp : hparams)
		v->visit(hp);
}
//!

//! LayerParams
void Input::accept(ASTVisitor* v)
{
	v->visit(inp);
}

void Output::accept(ASTVisitor* v)
{
	v->visit(outp);
}

void LayerName::accept(ASTVisitor* v)
{
	v->visit(name);
}
//!

//! LSTMParams
void InputSize::accept(ASTVisitor* v)
{
	v->visit(inSize);
	v->visit(llength);
}

void OutputTimestep::accept(ASTVisitor* v)
{
	v->visit(outStep);
}

void HiddenSize::accept(ASTVisitor* v)
{
	v->visit(hSize);
}

void NumLayers::accept(ASTVisitor* v)
{
	v->visit(nLayers);
}
//!

//! MLParams
void InFeatures::accept(ASTVisitor* v)
{
	v->visit(inF);
	v->visit(llength);
}

void OutFeatures::accept(ASTVisitor* v)
{
	for(auto &o : outFeat)
		v->visit(o);
}
//!

//! Expressions and Literals
void BinExpr::accept(ASTVisitor* v)
{
	v->visit(lhs);
	v->visit(rhs);
}

void LengthOf::accept(ASTVisitor* v)
{
	v->visit(layer);
}
//!
