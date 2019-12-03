#pragma once

#include "Lexer.h"
#include "Model.h"
#include "Identifier.h"

#include <memory>

class Parser
{	
public:
	Parser() = delete;
	Parser(std::unique_ptr<Lexer> &&l)
	{
		try
		{	lex = std::move(l);	}
		catch(CompExcept &ex)
		{	throw;				}
	}

	Parser(std::unique_ptr<Scanner> &&sc)
	{
		try
		{	lex = std::make_unique<Lexer>(std::move(sc));	}
		catch(CompExcept &ex)
		{	throw;				}
	}

	Parser(std::string fp)
	{
		try
		{	lex = std::make_unique<Lexer>(fp);		}
		catch(CompExcept &ex)
		{	throw;									}
	}
	
	~Parser()
	{
		lex = NULL;
		tokPend = NULL;
	}

private:

	inline bool accept(Token::TokenType&& ctt)
	{
	#ifdef PARDBG
		printf("PARSER:\t\taccept()\n");
	#endif
		return (tokPend ? *tokPend == ctt 
						: [this](){
						  tokPend = std::make_unique<Token>(lex->safeNextToken());
						  return *tokPend;}() == ctt);
	}

	inline Token expect(Token::TokenType &&ctt)
	{
	#ifdef PARDBG
		printf("PARSER:\t\texpect()\n");
	#endif
		if (!accept(std::move(ctt)))
			throw CompExcept("Parsing error bla bla");

		Token expected = *tokPend;
		tokPend = NULL;
		return expected;
	}

public:
	std::shared_ptr<Model> safeParseModel()
	{
		try 						{	model = parseModel();
										return model;			}
		catch (CompExcept& ex)		{	throw;					}	
	}

private:
	/***** Recursive descent parsing functions  *****/
	std::unique_ptr<Model> parseModel();
	std::unordered_set<std::unique_ptr<Import>> parseImport();
	std::unordered_set<std::unique_ptr<Attribute>> parseAttribute();
	std::unordered_set<std::unique_ptr<Layer>> parseLayer();
	void parseNewLines();

	Identifier *parseIdentifier(Token expID);

	std::string parseStrLiteral();
	bool parseBoolLiteral();

private:
	std::unique_ptr<Lexer> lex = NULL;
	std::unique_ptr<Token> tokPend = NULL;
	std::shared_ptr<Model> model = NULL;
};