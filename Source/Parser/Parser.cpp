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

setPtr<Import> Parser::parseImport()
{

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

setPtr<Attribute> Parser::parseAttribute()
{
    setPtr<Attribute> attr;

    while(accept(TType::DEFINE))
    {
        expect(TType::DEFINE);
        // Token defType = expect(TType::IDENTIFIER);
        // if (AttrIDTypes.find(defType.getData()) == AttrIDTypes.end())
        // {
        //     throw CompExcept("Parsing Error: Attribute identifier not found");
        // }
        // parseIdentifier(defType);
        AttrObj = parseIdentifier(expect(TType::IDENTIFIER);

        expect(TType::NEWLINE);
    }
    // new Attribute will be called here
    return attr;
}

setPtr<Layer> Parser::parseLayer()
{
    // setPtr<Layer> a;
    // return a;
    return {};
}

// template<typename T>
Token Parser::parseIdentifier(Token expID)
{
    std::string IDName = expID.getData();

    switch (IDName)
    {
        case "network_name":

    }
    return;
}