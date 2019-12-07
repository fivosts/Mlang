#pragma once

class BinExpr : public ASTNode
{
public:
	BinExpr() = delete;
	BinExpr(std::unique_ptr<BinExpr> b, std::string r) : lhs(std::move(b)), rhs(r) {}
	BinExpr(std::string r) : rhs(r) {}
	~BinExpr() = default;
private:
	std::unique_ptr<BinExpr> lhs = NULL;
	std::string rhs;
};
