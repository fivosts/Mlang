#include "Parser.h"
#include "Import.h"
#include "ModelProperties.h"
#include "LayerProperties.h"
#include <algorithm>


std::unique_ptr<Model> Parser::parseModel()
{

    /* The order of evaluation of function arguments is unspecified. */
    /* They have to be specified explicitly */
    setPtr<Import> imp;
    setPtr<Attribute> attr;
    setPtr<Layer> lay;

    parseImport(std::move(imp));
    parseAttribute(std::move(attr));
    parseLayer(std::move(lay));

    return std::make_unique<Model>(std::move(imp), std::move(attr), std::move(lay));
}

void Parser::parseImport(setPtr<Import> &&imports)
{
#ifdef PARDBG
    printf("PARSER:\t\tparseImport()\n");
#endif
    if (accept(TType::IMPORT))
    {
        expect(TType::IMPORT);
        Token importElement = expect(TType::STR_LITERAL);
        parseNewLines();
        imports.insert(std::make_unique<Import>(Import(importElement.getData())));
        parseImport(std::move(imports));   
    }
    return;
}

void Parser::parseAttribute(setPtr<Attribute> &&attributes)
{
#ifdef PARDBG
    printf("PARSER:\t\tparseAttribute()\n");
#endif

    if (accept(TType::DEFINE))
    {
        expect(TType::DEFINE);
        std::unique_ptr<Attribute> attr = parseIdentifier<Attribute>(expect(TType::IDENTIFIER));
        parseNewLines();
        attributes.insert(std::move(attr));
        parseAttribute(std::move(attributes));
    }
    return;
}

void Parser::parseLayer(setPtr<Layer> &&layers)
{
#ifdef PARDBG
    printf("PARSER:\t\tparseLayer()\n");
#endif
    if (accept(TType::IDENTIFIER))
    {
    	layers.insert(parseIdentifier<Layer>(expect(TType::IDENTIFIER)));
    	parseNewLines();
    	parseLayer(std::move(layers));
    }
    return;
}

template<typename T>
std::unique_ptr<T> Parser::parseIdentifier(Token /* expectedID */, specializer<T>)
{
    //TODO add info to the exception
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
        return std::unique_ptr<Attribute>(new InpTensors(parseStrArrLiteral()));
    }
    else if (IDName == "output_tensors")
    {
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
    expect(TType::ASSIGN);

    if (IDName == "input")
    {
        std::unique_ptr<BinExpr> e = parseBinExpr();
        parseNewLines();
        return std::unique_ptr<LayerParams>(new Input(std::move(e)));
    }
    else if (IDName == "output")
    {
        std::string str = parseStrLiteral();
        parseNewLines();
        return std::unique_ptr<LayerParams>(new Output(str));
    }
    else if (IDName == "layer_name")
    {
        std::string str = parseStrLiteral();
        parseNewLines();
        return std::unique_ptr<LayerParams>(new LayerName(str));
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
    expect(TType::ASSIGN);

    if (IDName == "input_size")
    {
    	//////// This should be better written here TODO
    	if (accept(TType::INT_LITERAL))
    	{
    		int id = parseIntLiteral();
    		parseNewLines();
	        return std::unique_ptr<LSTMParams>(new InputSize(id));
    	}
    	else
    	{
    		expect(TType::IDENTIFIER, "len");
    		expect(TType::LPAR);
    		std::unique_ptr<LengthOf> lexpr(new LengthOf(parseStrLiteral()));
	        expect(TType::RPAR);
	        parseNewLines();
	        return std::unique_ptr<LSTMParams>(new InputSize(std::move(lexpr)));
    	}
    	///////
    }
    else if (IDName == "output_timestep")
    {
    	int id = parseIntLiteral();
    	parseNewLines();
        return std::unique_ptr<LSTMParams>(new OutputTimestep(id));
    }
    else if (IDName == "hidden_size")
    {
    	int id = parseIntLiteral();
    	parseNewLines();
        return std::unique_ptr<LSTMParams>(new HiddenSize(id));
    }
    else if (IDName == "num_layers")
    {
    	int id = parseIntLiteral();
	    parseNewLines();
        return std::unique_ptr<LSTMParams>(new NumLayers(id));
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
    expect(TType::ASSIGN);
    
    if (IDName == "in_features")
    {
        //! TODO this looks troublesome
        // return new InFeatures<T>();
    }
    else if (IDName == "out_features")
    {
        int id = parseIntLiteral();
        parseNewLines();
        return std::unique_ptr<MLParams>(new OutFeatures(id));
    }
    else
    {
        throw CompExcept("Parsing Error: MLParam not recognized");
    }
    return nullptr;
}

std::unique_ptr<Layer> Parser::parseIdentifier(Token expectedID, specializer<Layer>)
{
    std::string IDName = expectedID.getData();
    if (accept(TType::NEWLINE))
    {
        parseNewLines();
    }
    expect(TType::LBRA);
    parseNewLines();
    setPtr<LayerParams> lParams;
    parseBlockParams<LayerParams>(std::move(lParams));
    std::unique_ptr<ParamBlock> pBlock(new ParamBlock(std::move(lParams)));

    if (IDName == "LSTM")
    {
        std::unique_ptr<HyperparamBlock> hBlock = parseHyperparamBlock<LSTMParams>();
        expect(TType::RBRA);
        return std::unique_ptr<LSTM>(new LSTM(std::move(pBlock), std::move(hBlock)));
    }
    else if (IDName == "MLP")
    {
        std::unique_ptr<HyperparamBlock> hBlock = parseHyperparamBlock<MLParams>();
        expect(TType::RBRA);
        return std::unique_ptr<MLP>(new MLP(std::move(pBlock), std::move(hBlock)));
    }
    else if (IDName == "SIGMOID")
    {
        expect(TType::RBRA);
        return std::unique_ptr<Sigmoid>(new Sigmoid(std::move(pBlock)));
    }
    else
    {
        throw CompExcept("Parsing Error: Layer not recognized");
    }

    return nullptr;
}

template<typename T>
std::unique_ptr<HyperparamBlock> Parser::parseHyperparamBlock()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseHyperparamBlock()\n");
#endif
    expect(TType::IDENTIFIER, "hyperparam_block");
    if (accept(TType::NEWLINE))
    {
        parseNewLines();
    }
    expect(TType::LBRA);
    parseNewLines(); 
    setPtr<HyperParams> params;
    parseBlockParams<T, HyperParams>(std::move(params));
    expect(TType::RBRA);
    parseNewLines();
    return std::unique_ptr<HyperparamBlock>(new HyperparamBlock(std::move(params)));
}

// T is the specific type specifier, U is the parent class
// in case polymorphism is needed.
template <typename T, typename U = T>
void Parser::parseBlockParams(setPtr<U> &&bp)
{
#ifdef PARDBG
    printf("PARSER:\t\tparseBlockParams()\n");
#endif
    if (accept(TType::IDENTIFIER) && !accept(TType::IDENTIFIER, "hyperparam_block")) // TODO make sure here that you only accept T
    {
        bp.insert(parseIdentifier<T>(expect(TType::IDENTIFIER)));
        parseBlockParams<T, U>(std::move(bp));
    }
    return;
}

void Parser::parseNewLines()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseNewLines()\n");
#endif
    expect(TType::NEWLINE);
    if (accept(TType::NEWLINE))
    {
        parseNewLines();
    }
    return;
}

std::string Parser::parseStrLiteral()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseStrLiteral()\n");
#endif
    return expect(TType::STR_LITERAL).getData();
}

std::unordered_set<std::string> Parser::parseStrArrLiteral()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseStrArrLiteral()\n");
#endif
    std::unordered_set<std::string> strArr;
    if (accept(TType::STR_LITERAL))
        return 
        {
            parseStrLiteral()
        };

    expect(TType::LSBR);
    if (!accept(TType::RSBR))
    {
        strArr.insert(parseStrLiteral());
        while(accept(TType::COMMA))
        {
            expect(TType::COMMA);
            strArr.insert(parseStrLiteral());
        }
    }
    expect(TType::RSBR);
    return strArr;
}

int Parser::parseIntLiteral()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseIntLiteral()\n");
#endif
    try
    {
        return (accept(TType::MINUS) ? [this](){expect(TType::MINUS); return -1;}() : 1) * 
        		std::stoi(expect(TType::INT_LITERAL).getData());
    }
    catch(const std::exception& e)
    {
        throw CompExcept("Parsing Error: Invalid int literal");
    }
}

bool Parser::parseBoolLiteral()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseBoolLiteral()\n");
#endif
    return expect(TType::BOOL_LITERAL).getData() == "True";
}

std::unique_ptr<BinExpr> Parser::parseBinExpr()
{
#ifdef PARDBG
    printf("PARSER:\t\tparseBinExpr()\n");
#endif
    std::string lhs = parseStrLiteral();
    if (accept(TType::PLUS))
    {
        expect(TType::PLUS);
        return std::unique_ptr<BinExpr>(new BinExpr(parseBinExpr(), lhs));
    }
    return std::unique_ptr<BinExpr>(new BinExpr(lhs));
}

