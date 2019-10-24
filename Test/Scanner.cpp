#include "gtest/gtest.h"
#include "Scanner.h"

#ifdef MODEL_PATH
#define FULL_PATH(M) MODEL_PATH M
#endif

namespace MLogTest
{
    TEST(ScannerTest, Empty)
    {
        ASSERT_NO_THROW({
            Scanner *t = new Scanner(FULL_PATH("empty.mlog"));
            while(t->nextChar() != EOF){}
        });
    }

    TEST(ScannerTest, Normal)
    {
        ASSERT_NO_THROW({
            Scanner *t = new Scanner(FULL_PATH("ase_model.mlog"));
            while(t->nextChar() != EOF){}
        });
    }

    TEST(ScannerTest, Binary){
        ASSERT_NO_THROW({
            Scanner *t = new Scanner(FULL_PATH("binary.mlog"));
            while(t->nextChar() != EOF){}
        });
    }

}

