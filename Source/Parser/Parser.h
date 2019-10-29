#pragma once

#include "Lexer.h"
#include "Model.h"

#include <memory>

class Parser
{	
public:
	Parser(Lexer l) : lex(l) {}
	~Parser() = default;

	/*!!
		Queue is not needed atm because lookAhead is not in plans
		Otherwise, queue will be implemented, and accept will load i
		items in the queue, as instructed by lookAhead
	!!*/
	inline bool accept(Token &exp)
	{
		/*
			if queue is empty, invoke lambda to fetch one from lexer
			Otherwise load the queue
			!!! Don't do unnecessary reads from lexer.
			Lexer should be responsible to cut this off
		*/
		return (tokPend ? *tokPend == exp : [this](){*tokPend = lex.nextToken();
												return *tokPend;} == exp);
	}

	template <typename T>
	bool expect(T &exp)
	{
		return !logErr(accept(ct));
	}

	template <typename T, typename... U>
	bool expect(T &ct, U... &rt)
	{
		return !logErr(accept(ct)) && expect(rt...);
	}

	/* To be refactored */
	inline bool logErr(bool &st)
	{
		if (st)
			return false;
		else
			// log the error somewhere: a) who b) where c) why
			return true;
	}

	std::shared_ptr<Model> parse() { return parseModel(); }

private:
	Lexer lex;
	std::unique_ptr<Token> tokPend = NULL;

private:
	/***** Recursive descent parsing functions  *****/
	std::unique_ptr<Model> parseModel();
	std::unique_ptr<Import> parseImport();
	std::unique_ptr<Attribute> parseAttribute();
	std::unique_ptr<Layer> parseLayer();
};