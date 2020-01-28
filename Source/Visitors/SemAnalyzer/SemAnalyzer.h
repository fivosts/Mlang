#pragma once

#include "ASTVisitor.h"
#include "ASTNode.h"

class NameAnalyzer : public ASTVisitor
{
public:
    NameAnalyzer(std::shared_ptr<Model> &&m) : model(std::move(m)) {}
    ~NameAnalyzer()
    {
        model = NULL;
    }

    std::shared_ptr<Model> safeVisit()
    {
        try                         {   model->accept(this);
                                        return model;               }
        catch (CompExcept& ex)      {   throw;                      }
    }

protected:
    std::shared_ptr<Model> model = NULL;
};


class TypeCheckAnalyzer : public ASTVisitor
{
public:
    TypeCheckAnalyzer(std::shared_ptr<Model> &&m) : model(std::move(m)) {}
    ~TypeCheckAnalyzer()
    {
        model = NULL;
    }

    std::shared_ptr<Model> safeVisit()
    {
        try                         {   model->accept(this);
                                        return model;               }
        catch (CompExcept& ex)      {   throw;                      }
    }
protected:
    std::shared_ptr<Model> model = NULL;
};  

class SemAnalyzer
{
public:
    SemAnalyzer() = default;
    ~SemAnalyzer() = default;

    std::shared_ptr<Model> safeVisit(std::shared_ptr<Model> &&m)
    {
        NameAnalyzer name(std::move(m));
        TypeCheckAnalyzer type(std::move(m));

        try                         {   name.safeVisit();
                                        type.safeVisit();
                                        return m;                }
        catch (CompExcept& ex)      {   throw;                       }
    }

    // Name Analysis in 3 aspects 
    // Includes: Does the module exist ?
    // Attributes: add to symbol table
    // Layers: add declared variables to symbol table
    // Then check if used symbols are legit.
    // Is scope in this context meaningful ?
};

