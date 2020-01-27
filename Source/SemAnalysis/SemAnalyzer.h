#pragma once

// #include <memory>

class SemAnalyzer
{
public:
    SemAnalyzer() = delete;
    SemAnalyzer(std::shared_ptr<Model> &&m) : model(std::move(m)) {}

    std::shared_ptr<Model> safeAnalyzeModel()
    {
        try                         {    AnalyzeModel();
                                        return model;            }
        catch (CompExcept& ex)        {    throw;                    }
    }

private:

    // Analyze model will call analyze name and types
    void AnalyzeModel()
    {
        AnalyzeNames();
        AnalyzeTypes();
        return;
    }

    // Name Analysis in 3 aspects 
    // Includes: Does the module exist ?
    // Attributes: add to symbol table
    // Layers: add declared variables to symbol table
    // Then check if used symbols are legit.
    // Is scope in this context meaningful ?
    void AnalyzeNames();
    void AnalyzeTypes();

private:
    std::shared_ptr<Model> model = NULL;
};