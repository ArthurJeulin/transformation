#include <gtest/gtest.h>
#include "aml.h"


TEST(TestSuiteSample,TestSample)
{
    int somme = 2+3;
    ASSERT_EQ(5,somme);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}