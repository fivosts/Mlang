#pragma once

#include "Lexer.h"
#include "Model.h"
#include "Identifier.h"
#include "Expression.h"

#include <memory>

template<typename T>
struct specializer {typedef T type; };

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

	inline bool accept(Token::TokenType&& ctt, std::string &&expStr)
	{
	#ifdef PARDBG
		printf("PARSER:\t\taccept()\n");
	#endif
		return (tokPend ? *tokPend == ctt && tokPend->getData() == expStr
						: [this](){
						  tokPend = std::make_unique<Token>(lex->safeNextToken());
						  return *tokPend;}() == ctt && tokPend->getData() == expStr);
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

	inline Token expect(Token::TokenType &&ctt, std::string &&expStr)
	{
	#ifdef PARDBG
		printf("PARSER:\t\texpect()\n");
	#endif
		if (!accept(std::move(ctt), std::move(expStr)))
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

	template<typename T>
	std::unique_ptr<T> parseIdentifier(Token expectedID)
	{
		return parseIdentifier(expectedID, specializer<T>());
	}

	template<typename T>
	std::unique_ptr<T> parseIdentifier(Token expectedID, specializer<T>);
	std::unique_ptr<Attribute> parseIdentifier(Token expectedID, specializer<Attribute>);
	std::unique_ptr<LayerParams> parseIdentifier(Token expectedID, specializer<LayerParams>);
	std::unique_ptr<LSTMParams> parseIdentifier(Token expectedID, specializer<LSTMParams>);
	std::unique_ptr<MLParams> parseIdentifier(Token expectedID, specializer<MLParams>);
	// std::unique_ptr<ASTNode> parseIdentifier(Token expectedID, specializer<ASTNode>);
	std::unique_ptr<Layer> parseIdentifier(Token expectedID, specializer<Layer>);

	std::string parseStrLiteral();

	//! TODO More dummy than ever!
	std::unordered_set<std::string> parseStrArrLiteral();

	bool parseBoolLiteral();
	int parseIntLiteral();
	
	template<typename T>
	std::unique_ptr<HyperparamBlock> parseHyperparamBlock();

	template<typename T>
	std::unordered_set<std::unique_ptr<T>> parseBlockParams();
	
	BinExpr parseBinExpr();

private:
	std::unique_ptr<Lexer> lex = NULL;
	std::unique_ptr<Token> tokPend = NULL;
	std::shared_ptr<Model> model = NULL;
};