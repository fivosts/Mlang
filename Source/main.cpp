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
#include <iostream>

typedef Token::TokenType type;

int main(){
	std::string line;
	Scanner *a = new Scanner("/home/foitsi01/MLog/Models/ase_model.mlog");
	// std::ifstream a;
	// a->open("/home/foitsi01/MLog/Models/ase_model.mlog");

	// auto b = a->getChar();

	// std::cout << b <<std::endl;

	Token t(Token::TokenType::IMPORT);

	if (t.getToken() == type::IMPORT){
		std::cout << "Yay!\n";
	}

	// while(b != EOF){
	// 	std::cout << (char)b;
	// 	b = a->getChar();
	// }

	return 0;
}
