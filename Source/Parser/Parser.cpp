#include "Parser.h"
#include "Import.h"
// template<typename T>
// using setPtr = std::unordered_set<std::unique_ptr<T>>;

template<typename T>
using setPtr = std::unordered_set<std::unique_ptr<T>>;
typedef Token::TokenType TType;


std::unique_ptr<Model> Parser::parseModel()
{
    return std::make_unique<Model>(parseImport(),
                                    parseAttribute(),
                                    parseLayer() );
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
    setPtr<Attribute> attr;

    while(accept(TType::DEFINE))
    {
        expect(TType::DEINE));
        Token defineElement = parseIdentifier(expect(TType::IDENTIFIER));
        expect(TType::NEWLINE);
    }

    return attr;
}

setPtr<Layer> Parser::parseLayer(){
    // setPtr<Layer> a;
    // return a;
    return {};
}
