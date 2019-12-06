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

    setPtr<Attribute> attrSet;
    while(accept(TType::DEFINE))
    {
        expect(TType::DEFINE);
        std::unique_ptr<Attribute> attr = parseIdentifier<Attribute>(expect(TType::IDENTIFIER));
        
        attr->printData();
        
        parseNewLines();
        attrSet.insert(std::move(attr));
    }
    return attrSet;
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

template<typename T>
std::unique_ptr<T> Parser::parseIdentifier(Token expectedID, specializer<T>)
{
    throw CompExcept("Parsing Error: Identifier type not recognized");
}

std::unique_ptr<Attribute> Parser::parseIdentifier(Token expectedID, specializer<Attribute>)
{
    std::string IDName = expectedID.getData();

    if (IDName == "network_name")
    {
        return std::unique_ptr<Attribute>(new NetworkName(parseStrLiteral()));
    }
    else if (IDName == "backend")
    {
        return std::unique_ptr<Attribute>(new Backend(parseStrLiteral()));
    }
    else if (IDName == "target")
    {
        return std::unique_ptr<Attribute>(new Target(parseStrLiteral()));
    }
    else if (IDName == "cuda_available")
    {
        return std::unique_ptr<Attribute>(new CUDA(parseBoolLiteral()));
    }
    else if (IDName == "input_tensors")
    {
        //! TODO this can be a string array
        return std::unique_ptr<Attribute>(new InpTensors(parseStrArrLiteral()));
    }
    else if (IDName == "output_tensors")
    {
        //! TODO this can be a string array
        return std::unique_ptr<Attribute>(new OutTensors(parseStrArrLiteral()));
    }
    else
    {
        throw CompExcept("Parsing Error: Attribute not recognized");
    }
    return nullptr;
}

std::unique_ptr<LayerParams> Parser::parseIdentifier(Token expectedID, specializer<LayerParams>)
{
    std::string IDName = expectedID.getData();

    if (IDName == "input")
    {
        return std::unique_ptr<LayerParams>(new Input(parseBinExpr()));
    }
    else if (IDName == "output")
    {
        return std::unique_ptr<LayerParams>(new Output(parseStrLiteral()));
    }
    else if (IDName == "layer_name")
    {
        return std::unique_ptr<LayerParams>(new LayerName(parseStrLiteral()));
    }
    else
    {
        throw CompExcept("Parsing Error: LayerParam not recognized");
    }
    return nullptr;
    
}

std::unique_ptr<LSTMParams> Parser::parseIdentifier(Token expectedID, specializer<LSTMParams>)
{
    std::string IDName = expectedID.getData();

    if (IDName == "input_size")
    {
        return std::unique_ptr<LSTMParams>(new InputSize(parseIntLiteral()));
    }
    else if (IDName == "output_timestep")
    {
        return std::unique_ptr<LSTMParams>(new OutputTimestep(parseIntLiteral()));
    }
    else if (IDName == "hidden_size")
    {
        return std::unique_ptr<LSTMParams>(new HiddenSize(parseIntLiteral()));
    }
    else if (IDName == "num_layers")
    {
        return std::unique_ptr<LSTMParams>(new NumLayers(parseIntLiteral()));
    }
    else
    {
        throw CompExcept("Parsing Error: LSTMParam not recognized");
    }
    return nullptr;
}

std::unique_ptr<MLParams> Parser::parseIdentifier(Token expectedID, specializer<MLParams>)
{
    std::string IDName = expectedID.getData();
    if (IDName == "in_features")
    {
        //! TODO this looks troublesome
        // return new InFeatures<T>();
    }
    else if (IDName == "out_features")
    {
        return std::unique_ptr<MLParams>(new OutFeatures(parseIntLiteral()));
    }
    else
    {
        throw CompExcept("Parsing Error: MLParam not recognized");
    }
    return nullptr;
}

std::unique_ptr<ASTNode> Parser::parseIdentifier(Token expectedID, specializer<ASTNode>)
{
    std::string IDName = expectedID.getData();
    
    if (IDName == "hyperparam_block")
    {
        // return parseHyperparamBlock();
        return parseHyperparamBlock();
    }
    else if (IDName == "len")
    {

    }
    else
    {
        throw CompExcept("Parsing Error: ASTNode not recognized");
    }
    return nullptr;
}

std::unique_ptr<Layer> Parser::parseIdentifier(Token expectedID, specializer<Layer>)
{
    std::string IDName = expectedID.getData();
   
    if (IDName == "LSTM")
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
        throw CompExcept("Parsing Error: Layer not recognized");
    }

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

std::unique_ptr<HyperparamBlock> Parser::parseHyperparamBlock()
{
#ifdef PARDBG
    printf("PARSER:\t\parseHyperparamBlock()\n");
#endif
    return std::unique_ptr<HyperparamBlock>(new HyperparamBlock());
}

//! TODO Dummy
bool Parser::parseBoolLiteral()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseBoolLiteral()\n");
#endif

    return true;
}
