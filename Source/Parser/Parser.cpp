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
        Attribute* AttrObj = static_cast<Attribute*>(parseIdentifier(expect(TType::IDENTIFIER)));
        // Identifier* AttrObj = parseIdentifier(expect(TType::IDENTIFIER));

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
        return new Backend(parseStrLiteral());
    }
    else if (IDName == "target")
    {
        return new Target(parseStrLiteral());
    }
    else if (IDName == "cuda_available")
    {
        return new CUDA(parseBoolLiteral());
    }
    else if (IDName == "input_tensors")
    {
        //! TODO this can be a string array
        return new InpTensors(parseStrArrLiteral());
    }
    else if (IDName == "output_tensors")
    {
        //! TODO this can be a string array
        return new OutTensors(parseStrArrLiteral());
    }
    ////////////////////////
    //! LayerParams
    ////////////////////////
    else if (IDName == "input")
    {
        return new Input(parseBinExpr());
    }
    else if (IDName == "output")
    {
        return new Output(parseStrLiteral());
    }
    else if (IDName == "layer_name")
    {
        return new LayerName(parseStrLiteral());
    }
    ////////////////////////
    //! LSTMParams
    ////////////////////////
    else if (IDName == "input_size")
    {
        return new InputSize(parseIntLiteral());
    }
    else if (IDName == "output_timestep")
    {
        return new OutputTimestep(parseIntLiteral());
    }
    else if (IDName == "hidden_size")
    {
        return new HiddenSize(parseIntLiteral());
    }
    else if (IDName == "num_layers")
    {
        return new NumLayers(parseIntLiteral());
    }
    ////////////////////////
    //! MLParams
    ////////////////////////
    else if (IDName == "in_features")
    {
        //! TODO this looks troublesome
        // return new InFeatures<T>();
    }
    else if (IDName == "out_features")
    {
        return new OutFeatures(parseIntLiteral());
    }
    ////////////////////////
    //! ASTNode
    ////////////////////////
    else if (IDName == "hyperparam_block")
    {
        // return parseHyperparamBlock();
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

//! TODO Dummy
std::string Parser::parseStrLiteral()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseStrLiteral()\n");
#endif
    return "a";
}

//! TODO Dummy!
std::unordered_set<std::string> Parser::parseStrArrLiteral()
{
    return {"a", "b"};
}

//! TODO Dummy!!
int Parser::parseIntLiteral()
{
    return 0;
}

//! TODO Dummy!!
BinExpr Parser::parseBinExpr()
{
    return BinExpr();
}

//! TODO Dummy!
std::unique_ptr<HyperparamBlock> Parser::parseHyperparamBlock()
{
    return std::move(std::unique_ptr<HyperparamBlock>(new HyperparamBlock()));
}

//! TODO Dummy
bool Parser::parseBoolLiteral()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseBoolLiteral()\n");
#endif

    return true;
}
