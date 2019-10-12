#ifndef BINEXPR_H
#define BINEXPR_H

class BinExpr{
public:
	BinExpr() = default;
	~BinExpr() = default;
private:
	BinExpr* lhs{NULL};
	std::string rhs;
};

#endif