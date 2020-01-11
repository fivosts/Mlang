#pragma once

// #include <memory>

class SemAnalyzer
{
public:
	SemAnalyzer() = delete;
	SemAnalyzer(std::shared_ptr<Model> &&m) : model(std::move(m)) {}

	std::shared_ptr<Model> safeAnalyzeModel()
	{
		try 						{	AnalyzeModel();
										return model;			}
		catch (CompExcept& ex)		{	throw;					}
	}

private:
	void AnalyzeModel();
	void AnalyzeNames();
	void AnalyzeTypes();

private:
	std::shared_ptr<Model> model = NULL;
};