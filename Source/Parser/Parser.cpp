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
        Token defType = parseIdentifier<Attribute>(expect(TType::IDENTIFIER));
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

template<typename T>
Token parseIdentifier(Token expID)
{
    // if data of identifier belongs to the map of T, then we are fine
    if (T::IDMap.find(expID.getData()) != T::IDMap.end())
    {
        // element found in the type's map and everything is fine
    }
    else
    {
        // We've got a parsing error because the wrong identifier was used for a specific field.
        throw CompExcept(joinWhSpace("Parsing Error", expID.getStrPos(), "Identifier", expID.getData(), "not found for type", T::));
    }
}