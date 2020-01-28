#pragma once

#include "ASTNode.h"

#include <memory>

class BinExpr : public ASTNode
{
public:
	BinExpr() = delete;
	BinExpr(std::unique_ptr<BinExpr> &&b, std::string r) : lhs(std::move(b)), rhs(r) {}
	BinExpr(std::string r) : rhs(r) {}
	~BinExpr() = default;

	void accept(ASTVisitor* v) override;

private:
	std::unique_ptr<BinExpr> lhs = NULL;
	std::string rhs;
};
