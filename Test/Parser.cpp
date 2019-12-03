#include "gtest/gtest.h"
#include <unordered_set>

#include "Lexer.h"

#ifdef MODEL_PATH
#define FULL_PATH(M) MODEL_PATH M
#endif

namespace
{
    auto getSc = [](const char *file){
                    std::unique_ptr<Scanner> sc(new Scanner(file));
                    return std::move(sc);
                    };
}

// TODO test constructors as well
// TODO all tests for parser. WARNING, they are copy-paste atm

namespace MLogTest
{
    TEST(ParserTest, Empty)
    {
        Lexer lex(getSc(FULL_PATH("empty.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INVALID) == TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, Normal)
    {
        Lexer lex(getSc(FULL_PATH("ase_model.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INVALID) == TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, Binary)
    {
        Lexer lex(getSc(FULL_PATH("binary.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INVALID) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, BadString1)
    {
        Lexer lex(getSc(FULL_PATH("bad_string1.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INVALID) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, BadString2)
    {
        Lexer lex(getSc(FULL_PATH("bad_string2.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INVALID) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, BadString3)
    {
        Lexer lex(getSc(FULL_PATH("bad_string3.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INVALID) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, BadString4)
    {
        Lexer lex(getSc(FULL_PATH("bad_string4.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INVALID) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, BadID1)
    {
        Lexer lex(getSc(FULL_PATH("bad_id1.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INVALID) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, Bool1)
    {
        Lexer lex(getSc(FULL_PATH("bool1.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::BOOL_LITERAL) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, Bool2)
    {
        Lexer lex(getSc(FULL_PATH("bool2.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::BOOL_LITERAL) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }

    TEST(ParserTest, BadInt1)
    {
        Lexer lex(getSc(FULL_PATH("bad_int1.mlog")));
        std::unordered_set<Token::TokenType> TokenBag;
        
        Token curr = lex.nextToken();
        TokenBag.insert(curr.getToken());
        while(curr.getToken() != Token::TokenType::END)
        {
            curr = lex.nextToken();
            TokenBag.insert(curr.getToken());
        }
        ASSERT_TRUE(TokenBag.find(Token::TokenType::INT_LITERAL) != TokenBag.end());
        ASSERT_FALSE(TokenBag.find(Token::TokenType::END) == TokenBag.end());
    }
}

