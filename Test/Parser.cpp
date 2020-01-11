#include "gtest/gtest.h"
#include <unordered_set>

#include "Parser.h"

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

namespace MLogTest
{
	TEST(ParserTest, StrConstructor1)
	{
		ASSERT_THROW(Parser par(FULL_PATH("invalid")), CompExcept );
	}

	TEST(ParserTest, StrConstructor2)
	{
		ASSERT_NO_THROW(Parser par(FULL_PATH("empty.mlog")));
	}

	TEST(ParserTest, LexConstructor)
	{
		std::unique_ptr<Lexer> lex(new Lexer(FULL_PATH("empty.mlog")));
		ASSERT_NO_THROW(Parser par(std::move(lex)));
	}

	TEST(ParserTest, ScConstructor)
	{
		std::unique_ptr<Scanner> sc(new Scanner(FULL_PATH("empty.mlog")));
		ASSERT_NO_THROW(Parser par(std::move(sc)));
	}

    TEST(ParserTest, Empty)
    {
        Parser par(FULL_PATH("empty.mlog"));
        ASSERT_NO_THROW(par.safeParseModel());
    }

    TEST(ParserTest, Normal)
    {
        Parser par(FULL_PATH("ase_model.mlog"));
        ASSERT_NO_THROW(par.safeParseModel());
    }

    TEST(ParserTest, Binary)
    {
        Parser par(FULL_PATH("binary.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }

    TEST(ParserTest, BadString1)
    {
        Parser par(FULL_PATH("bad_string1.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }

    TEST(ParserTest, BadString2)
    {
        Parser par(FULL_PATH("bad_string2.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }

    TEST(ParserTest, BadString3)
    {
        Parser par(FULL_PATH("bad_string3.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }

    TEST(ParserTest, BadString4)
    {
        Parser par(FULL_PATH("bad_string4.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }

    TEST(ParserTest, BadID1)
    {
        Parser par(FULL_PATH("bad_id1.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }

    TEST(ParserTest, Bool1)
    {
        Parser par(FULL_PATH("bool1.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }

    TEST(ParserTest, Bool2)
    {
        Parser par(FULL_PATH("bool2.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }

    TEST(ParserTest, BadInt1)
    {
        Parser par(FULL_PATH("bad_int1.mlog"));
        ASSERT_THROW(par.safeParseModel(), CompExcept);
    }
}

