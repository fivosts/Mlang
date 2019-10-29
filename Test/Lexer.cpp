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
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("empty.mlog")));
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
    }

    TEST(LexerTest, Normal)
    {
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("ase_model.mlog")));
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
    }

    TEST(LexerTest, Binary)
    {
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("binary.mlog")));
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
    }

    TEST(LexerTest, BadString1)
    {
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("bad_string1.mlog")));
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
    }

    TEST(LexerTest, BadString2)
    {
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("bad_string2.mlog")));
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
    }

    TEST(LexerTest, BadString3)
    {
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("bad_string3.mlog")));
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
    }

    TEST(LexerTest, BadString4)
    {
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("bad_string4.mlog")));
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
    }

    TEST(LexerTest, BadID1)
    {
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("bad_id1.mlog")));
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
    }

    TEST(LexerTest, Bool1)
    {
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("bool1.mlog")));
        Lexer lex(sc);
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
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("bool2.mlog")));
        Lexer lex(sc);
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
        std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("bad_int1.mlog")));
        Lexer lex(sc);
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

