#include "gtest/gtest.h"
#include "Scanner.h"

#ifdef MODEL_PATH
#define FULL_PATH(M) MODEL_PATH M
#endif

static Scanner *sc;

namespace MlangTest
{
    TEST(ScannerTest, Empty)
    {
        ASSERT_NO_THROW({
            sc = new Scanner(FULL_PATH("empty.mlog"));
        });
        ASSERT_NO_THROW({
            while(sc->nextChar() != EOF){}
        });
    }

    TEST(ScannerTest, Normal)
    {
        ASSERT_NO_THROW({
            sc = new Scanner(FULL_PATH("ase_model.mlog"));
        });
        ASSERT_NO_THROW({
            while(sc->nextChar() != EOF){}
        });
    }

    TEST(ScannerTest, Binary)
    {
        ASSERT_NO_THROW({
            sc = new Scanner(FULL_PATH("binary.mlog"));
        });
        ASSERT_NO_THROW({
            while(sc->nextChar() != EOF){}
        });
    }
}
