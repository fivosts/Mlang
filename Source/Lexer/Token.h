#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#ifdef TEST
	#include <unordered_map>
#endif

#define FOR_TOKENTYPES(TOKENIZE) \
TOKENIZE(IMPORT)	TOKENIZE(DEFINE)	TOKENIZE(IDENTIFIER)	TOKENIZE(NEWLINE) \
TOKENIZE(PLUS)		TOKENIZE(ASSIGN)	TOKENIZE(STR_LITERAL)	TOKENIZE(INT_LITERAL) \
TOKENIZE(BOOL_LITERAL)	TOKENIZE(LBRA)	TOKENIZE(RBRA)			TOKENIZE(LPAR) \
TOKENIZE(RPAR)		TOKENIZE(LSBR)		TOKENIZE(RSBR)			TOKENIZE(END) \
TOKENIZE(INVALID)

#define TOKEN_ENUMCLASS(TOKEN) TOKEN,
#define TOKEN_STRING(TOKEN) #TOKEN
#define TOKEN_MAP(TOKEN)  {TokenType::TOKEN, #TOKEN },
#define PRINT_TOKEN(TOKEN, CHAR) ( \
			std::cout << TOKEN << " " << CHAR << std::endl \
		)

class Token
{
public:

	enum class TokenType
	{		
		/******
			IMPORT,			// #import module
			DEFINE,			// #define target Pytorch
			
			IDENTIFIER, 	// identifier (see grammar)

			NEWLINE,		// '\n'
			PLUS,			// '+'
			ASSIGN,			// '='

			STR_LITERAL,	// "([a-z] | [A-Z] | [0-9] | '_')*"
			INT_LITERAL,	// ([0-9])*
			BOOL_LITERAL,	// True/False true/false 1/0

			LBRA,			// '{'
			RBRA,			// '}'
			LPAR,			// '('
			RPAR,			// ')'
			LSBR,			// '['
			RSBR,			// ']'

			END,			// EOF
			INVALID			// Unk token
		******/
		FOR_TOKENTYPES(TOKEN_ENUMCLASS)
	};

    using Position = std::pair<int, int>;

	Token() = delete;
	//maybe add template instead of overload ?
	Token(TokenType t, Position p, std::string d = "") : token(t), pos(p), data(d) {
 		#ifdef TEST
			PRINT_TOKEN(tokenMap[t], d);
		#endif
	}
	Token(TokenType t, Position p, char d) : token(t), pos(p), data((const char*)&d) {
		#ifdef TEST
			PRINT_TOKEN(tokenMap[t], d);
		#endif
	}
	~Token() = default;

	const TokenType &getToken() const{
		return token;
	}

private:
	TokenType token;
	std::string data;
	Position pos;
	public:
	#ifdef TEST
		static std::unordered_map<TokenType, std::string> tokenMap;
	#endif
};

#endif
