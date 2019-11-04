#include "Parser.h"
#include "Import.h"
// template<typename T>
// using setPtr = std::unordered_set<std::unique_ptr<T>>;

template<typename T>
using setPtr = std::unordered_set<std::unique_ptr<T>>;
typedef Token::TokenType TType;


std::unique_ptr<Model> Parser::parseModel()
{
    return std::make_unique<Model>(Parser::parseImport(),
                                    Parser::parseAttribute(),
                                    Parser::parseLayer() );
}

setPtr<Import> Parser::parseImport(){

    setPtr<Import> imports;
    while(accept(TType::IMPORT))
    {
        expect(TType::IMPORT);
        Token importElement = expect(TType::STR_LITERAL);
        expect(TType::NEWLINE);
        imports.insert(std::make_unique<Import>(Import(importElement.getData())));
    }

    return imports;
}

setPtr<Attribute> Parser::parseAttribute(){
    // setPtr<Attribute> a;
    // return a;
    return {};
}

setPtr<Layer> Parser::parseLayer(){
    // setPtr<Layer> a;
    // return a;
    return {};
}
