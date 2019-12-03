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

    /* The order of evaluation of function arguments is unspecified. */
    /* They have to be specified explicitly */
    setPtr<Import> tempA = parseImport();
    setPtr<Attribute> tempB = parseAttribute();
    setPtr<Layer> tempC = parseLayer();
    return std::make_unique<Model>(std::move(tempA), std::move(tempB), std::move(tempC));
}

setPtr<Import> Parser::parseImport()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseImport()\n");
#endif
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
#ifdef PARDBG
    printf("PARSER:\t\tparseNewLines()\n");
#endif
    expect(TType::NEWLINE);
    while (accept(TType::NEWLINE))
    {
        expect(TType::NEWLINE);
    }
    return;
}

setPtr<Attribute> Parser::parseAttribute()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseAttribute()\n");
#endif

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

        // This obj should be of type subclass and have constructed its members already
        // std::unique_ptr<Attribute> AttrObj = static_cast<Attribute*>(parseIdentifier(expect(TType::IDENTIFIER)));
        // Attribute* AttrObj = static_cast<Attribute*>(parseIdentifier(expect(TType::IDENTIFIER)));
        Identifier* AttrObj = parseIdentifier(expect(TType::IDENTIFIER));

        AttrObj->printData();

        parseNewLines();
    }
    // new Attribute will be called here
    return attr;
}

setPtr<Layer> Parser::parseLayer()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseLayer()\n");
#endif
    // setPtr<Layer> a;
    // return a;
    return {};
}

// Dummy
std::string parseStrLiteral()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseStrLiteral()\n");
#endif
    return "a";
}

Identifier* Parser::parseIdentifier(Token expID)
{
#ifdef PARDBG
    printf("PARSER:\t\tparseIdentifier()\n");
#endif
    std::string IDName = expID.getData();

    ////////////////////////
    //! Attributes
    ////////////////////////
    if (IDName == "network_name")
    {
        return new NetworkName(parseStrLiteral());
    }
    else if (IDName == "backend")
    {

    }
    else if (IDName == "target")
    {

    }
    else if (IDname == "cuda_available")
    {

    }
    else if (IDName == "input_tensors")
    {

    }
    else if (IDName == "output_tensors")
    {

    }
    ////////////////////////
    //! LayerParams
    ////////////////////////
    else if (IDName == "input")
    {

    }
    else if (IDName == "output")
    {

    }
    else if (IDName == "layer_name")
    {

    }
    ////////////////////////
    //! LSTMParams
    ////////////////////////
    else if (IDName == "input_size")
    {

    }
    else if (IDName == "output_timestep")
    {

    }
    else if (IDName == "hidden_size")
    {

    }
    else if (IDName == "num_layers")
    {

    }
    ////////////////////////
    //! MLParams
    ////////////////////////
    else if (IDName == "in_features")
    {

    }
    else if (IDName == "out_features")
    {

    }
    ////////////////////////
    //! ASTNode
    ////////////////////////
    else if (IDName == "hyperparam_block")
    {

    }
    else if (IDName == "len")
    {

    }
    ////////////////////////
    //! Layer
    ////////////////////////
    else if (IDName == "LSTM")
    {

    }
    else if (IDName == "MLP")
    {

    }
    else if (IDName == "SIGMOID")
    {

    }
    else
    {
        // crash
        // TODO this
        throw;
    }

    // TODO this
    return nullptr;

}

