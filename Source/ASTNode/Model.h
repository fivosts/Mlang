#pragma once

#include "ASTNode.h"
#include "Model.h"
#include "Import.h"
#include "Attribute.h"
#include "Layer.h"

#include <vector>
#include <unordered_set>

class Model : ASTNode
{
public:

	template<typename T>
	using setPtr = std::unordered_set<std::unique_ptr<T>>;

	Model() = delete;
	Model(setPtr<Import> &&i,
		  setPtr<Attribute> &&a,
		  setPtr<Layer> &&l) : imp(std::move(i)), attr(std::move(a)), lr(std::move(l)) {}
	
	virtual ~Model() override
	{
		// imp = NULL;
		// attr = NULL;
		// lr = NULL;
	}

	void accept(ASTVisitor* v) override;

private:
	setPtr<Import> imp;
	setPtr<Attribute> attr;
	setPtr<Layer> lr;
};
