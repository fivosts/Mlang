#pragma once

class BinExpr : public ASTNode
{
public:
	BinExpr() = delete;
	BinExpr(std::unique_ptr<BinExpr> b) : lhs(std::move(b)) {}
	~BinExpr() = default;
private:
	std::unique_ptr<BinExpr> lhs;
	std::string rhs;
};
