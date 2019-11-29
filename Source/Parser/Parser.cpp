#include "Parser.h"
#include "Import.h"
#include "ModelProperties.h"
#include "LayerProperties.h"
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
        parseNewLines();
        imports.insert(std::make_unique<Import>(Import(importElement.getData())));
    }
    return imports;
}

void Parser::parseNewLines()
{
    expect(TType::NEWLINE);
    while (accept(TType::NEWLINE))
    {
        expect(TType::NEWLINE);
    }
    return;
}

setPtr<Attribute> Parser::parseAttribute()
{
    setPtr<Attribute> attr;

    std::cout << "Attributes\n";
    while(accept(TType::DEFINE))
    {
        expect(TType::DEFINE);
        // Token defType = expect(TType::IDENTIFIER);
        // if (AttrIDTypes.find(defType.getData()) == AttrIDTypes.end())
        // {
        //     throw CompExcept("Parsing Error: Attribute identifier not found");
        // }
        // parseIdentifier(defType);
    std::cout << "In while\n";

        // This obj should be of type subclass and have constructed its members already
        // std::unique_ptr<Attribute> AttrObj = static_cast<Attribute*>(parseIdentifier(expect(TType::IDENTIFIER)));
        Attribute* AttrObj = static_cast<Attribute*>(parseIdentifier(expect(TType::IDENTIFIER)));

        AttrObj->printData();

        parseNewLines();
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

// Dummy
std::string parseStrLiteral()
{
    return "a";
}

// template<typename T>
Identifier* Parser::parseIdentifier(Token expID)
{
    std::string IDName = expID.getData();

    if (IDName == "network_name")
    {
        return new NetworkName(parseStrLiteral());
    }
    else if (IDName == "layer_name")
    {
        return new LayerName(parseStrLiteral());
    }

    return nullptr;
    // switch (IDName)
    // {
    //     case "network_name":
            // That here is the field of the object
            // that will be constructed
        
        // case "cuda_available":
        //     parseBoolLiteral();
        //     break;
        
        // case "backend":
        //     parseStrLiteral();
        //     break;
        
        // case "target":
        //     parseStrLiteral();
        //     break;
        
        // case "input_tensors":
        //     parseStrArray();
        //     break;
        
        // case "output_tensors":
        //     parseStrArray();
        //     break;
        
    //     default:
    //         throw CompExcept("Parsing Error: Identifier not recognized");
    //         break;
    // }
}

