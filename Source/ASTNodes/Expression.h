#pragma once

class BinExpr : public ASTNode
{
public:
	BinExpr() = default;
	~BinExpr() {delte lhs;}
private:
	BinExpr* lhs{NULL};
	std::string rhs;
};
