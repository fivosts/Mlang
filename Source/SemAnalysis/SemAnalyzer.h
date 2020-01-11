#pragma once

// #include <memory>

class SemAnalyzer
{
public:
	SemAnalyzer() = delete;
	SemAnalyzer(std::shared_ptr<Model> &&m) : model(std::move(m)) {}

	

private:
	std::shared_ptr<Model> model = NULL;
};