#pragma once

class Parser
{	
public:
	Parser(Lexer l) : lex(l) {}
	~Parser() = default;

	bool accept(Token::TokenType &exp)
	{

	}
	bool expect(Token::TokenType &exp);

	Model parse() { return parseModel(); }

private:
	Lexer lex;
	std::queue<Token::TokenType>

private:
	/***** Recursive descent parsing functions  *****/
	Model parseModel();
	Import parseImport();
	Attribute parseAttribute();
	Layer parseLayer();
};