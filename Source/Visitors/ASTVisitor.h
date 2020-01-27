#pragma once

/* Forward declaration of ast types */

class Model;
class LayerParams;

class ASTVisitor
{
public:
	ASTVisitor() = default;
	virtual ~ASTVisitor() = 0;

	virtual void visit(std::string /*s*/){}
	virtual void visit(std::unique_ptr<LayerParams> lp){
		(void)lp;
	}

protected:
	std::shared_ptr<Model> model = NULL;
};
