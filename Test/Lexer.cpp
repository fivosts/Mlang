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
                    return sc;
                    };
}

namespace MlangTest
{
    TEST(LexerTest, Empty)
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

    TEST(LexerTest, Normal)
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

    TEST(LexerTest, Binary)
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

    TEST(LexerTest, BadString1)
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

    TEST(LexerTest, BadString2)
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

    TEST(LexerTest, BadString3)
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

    TEST(LexerTest, BadString4)
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

    TEST(LexerTest, BadID1)
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

    TEST(LexerTest, Bool1)
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

    TEST(LexerTest, Bool2)
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

    TEST(LexerTest, BadInt1)
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

