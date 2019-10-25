#include "gtest/gtest.h"
#include <unordered_set>

#include "Lexer.h"

#ifdef MODEL_PATH
#define FULL_PATH(M) MODEL_PATH M
#endif

static Scanner *sc;

namespace MLogTest
{
    TEST(LexerTest, Empty)
    {
        sc = new Scanner(FULL_PATH("empty.mlog"));
        Lexer lex(sc);
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

        delete sc;
    }

    TEST(LexerTest, Normal)
    {
        sc = new Scanner(FULL_PATH("ase_model.mlog"));
        Lexer lex(sc);
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

        delete sc;
    }

    TEST(LexerTest, Binary)
    {
        sc = new Scanner(FULL_PATH("binary.mlog"));
        Lexer lex(sc);
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

        delete sc;
    }

    TEST(LexerTest, BadString1)
    {
        sc = new Scanner(FULL_PATH("bad_string1.mlog"));
        Lexer lex(sc);
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

        delete sc;
    }

    TEST(LexerTest, BadString2)
    {
        sc = new Scanner(FULL_PATH("bad_string2.mlog"));
        Lexer lex(sc);
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

        delete sc;
    }

    TEST(LexerTest, BadString3)
    {
        sc = new Scanner(FULL_PATH("bad_string3.mlog"));
        Lexer lex(sc);
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

        delete sc;
    }

    TEST(LexerTest, BadString4)
    {
        sc = new Scanner(FULL_PATH("bad_string4.mlog"));
        Lexer lex(sc);
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

        delete sc;
    }
}

