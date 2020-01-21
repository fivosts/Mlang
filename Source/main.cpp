// #include "ASTNode.h"
// #include "Attribute.h"
// #include "Block.h"
// #include "Expression.h"
// #include "Import.h"
// #include "Layer.h"
// #include "LayerProperties.h"
// #include "LengthOf.h"
// #include "Model.h"
// #include "ModelProperties.h"
// #include "Params.h"
#include "Scanner.h"
#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "SemAnalyzer.h"
#include <iostream>

#define TEST_PATH "./Models/ase_model.mlog"

typedef Token::TokenType type;

int main(){

	try{
		std::unique_ptr<Parser> p(new Parser(TEST_PATH));
		SemAnalyzer s(p->safeParseModel());
	}
	catch(CompExcept &e){
		std::cout << "Oops: " << e.what() << std::endl;
	}
	// std::ifstream a;
	// a->open("/home/foitsi01/Mlang/Models/ase_model.mlog");

	// auto b = a->getChar();

	// std::cout << b <<std::endl;

	// Token t(Token::TokenType::IMPORT, );

	// if (t.getToken() == type::IMPORT){
	// 	std::cout << "Yay!\n";
	// }

	// Lexer test(a);
	// test.nextToken();

	// while(b != EOF){
	// 	std::cout << (char)b;
	// 	b = a->getChar();
	// }

	return 0;
}
