#include "Parser.h"
#include "Import.h"
// template<typename T>
// using setPtr = std::unordered_set<std::unique_ptr<T>>;

typedef Token::TokenType TType;

std::unique_ptr<Model> Parser::parseModel()
{
    return std::make_unique<Model>(Parser::parseImport(),
                                    Parser::parseAttribute(),
                                    Parser::parseLayer() );
}

std::unordered_set<std::unique_ptr<Import>> Parser::parseImport(){
    // std::unordered_set<std::unique_ptr<Import>> a;
    // return a;
    while(accept(TType::IMPORT))
    {
        expect(TType::IMPORT);
        // on the fly push the return of expect to the set
        Token impPath = expect(TType::STR_LITERAL);
        expect(TType::NEWLINE);
    }

    return {};
}

std::unordered_set<std::unique_ptr<Attribute>> Parser::parseAttribute(){
    // std::unordered_set<std::unique_ptr<Attribute>> a;
    // return a;
    return {};
}

std::unordered_set<std::unique_ptr<Layer>> Parser::parseLayer(){
    // std::unordered_set<std::unique_ptr<Layer>> a;
    // return a;
    return {};
}
