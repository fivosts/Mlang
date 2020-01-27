#pragma once

#include "ASTVisitor.h"

class SemAnalyzer
{
public:
    SemAnalyzer() = default;
    ~SemAnalyzer()
    {
        model = NULL;
    }

    std::shared_ptr<Model> safeVisit(std::shared_ptr<Model> &&m)
    {
        std::shared_ptr<Model> model(std::move(m));
        std::shared_ptr<NameAnalyzer> name(std::move(model));
        std::shared_ptr<TypeCheckAnalyzer> type(std::move(model));

        try                         {   name->safeVisit();
                                        type->safeVisit();
                                        return model;                }
        catch (CompExcept& ex)      {   throw;                       }
    }

    // Name Analysis in 3 aspects 
    // Includes: Does the module exist ?
    // Attributes: add to symbol table
    // Layers: add declared variables to symbol table
    // Then check if used symbols are legit.
    // Is scope in this context meaningful ?
};

class NameAnalyzer : public ASTVisitor
{
    NameAnalyzer(std::shared_ptr<Model> &&m) : model(std::move(m)) {}
    ~NameAnalyzer()
    {
        model = NULL;
    }

    std::shared_ptr<Model> safeVisit()
    {
        try                         {   model->visit(this);
                                        return model;               }
        catch (CompExcept& ex)      {   throw;                      }
    }


};


class TypeCheckAnalyzer : public ASTVisitor
{
    TypeCheckAnalyzer(std::shared_ptr<Model> &&m) : model(std::move(m)) {}
    ~TypeCheckAnalyzer()
    {
        model = NULL;
    }

    std::shared_ptr<Model> safeVisit()
    {
        try                         {   model->visit(this);
                                        return model;               }
        catch (CompExcept& ex)      {   throw;                      }
    }

};  
