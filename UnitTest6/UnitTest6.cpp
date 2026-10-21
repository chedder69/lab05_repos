#include "pch.h"
#include "CppUnitTest.h"

#define main lab_main
#include "../PR5.5/PR5.5.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5_5_Tests
{
    TEST_CLASS(PascalTests)
    {
    public:

        TEST_METHOD(TestFirstElement)
        {
            int depth = 0;

            Assert::AreEqual(1LL, C(0, 0, 1, depth));
            Assert::AreEqual(1, depth);
        }

        TEST_METHOD(TestMiddleElement)
        {
            int depth = 0;

            Assert::AreEqual(6LL, C(4, 2, 1, depth));
            Assert::AreEqual(4, depth);
        }

        TEST_METHOD(TestNextRow)
        {
            int depth = 0;

            Assert::AreEqual(10LL, C(5, 2, 1, depth));
            Assert::AreEqual(5, depth);
        }

        TEST_METHOD(TestEdgeElement)
        {
            int depth = 0;

            Assert::AreEqual(1LL, C(5, 5, 1, depth));
            Assert::AreEqual(1, depth);
        }
    };
}