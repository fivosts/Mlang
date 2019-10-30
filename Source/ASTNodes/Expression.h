#pragma once

class BinExpr : public ASTNode
{
public:
	BinExpr() = default;
	~BinExpr() {delete lhs;}
private:
	BinExpr* lhs{NULL};
	std::string rhs;
};
