#include "pch.h"
#include "CppUnitTest.h"

#define main lab_main
#include "../PR5.4/PR5.4.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5_4_Tests
{
    TEST_CLASS(SumTests)
    {
    public:

        TEST_METHOD(TestS0)
        {
            double expected = 3.685705852322307;

            Assert::AreEqual(expected, S0(1, 3), 1e-10);
        }

        TEST_METHOD(TestS1)
        {
            double expected = 3.685705852322307;

            Assert::AreEqual(expected, S1(1, 3, 1), 1e-10);
        }

        TEST_METHOD(TestS2)
        {
            double expected = 3.685705852322307;

            Assert::AreEqual(expected, S2(1, 3, 3), 1e-10);
        }

        TEST_METHOD(TestS3)
        {
            double expected = 3.685705852322307;

            Assert::AreEqual(expected, S3(1, 3, 1, 0), 1e-10);
        }

        TEST_METHOD(TestS4)
        {
            double expected = 3.685705852322307;

            Assert::AreEqual(expected, S4(1, 3, 3, 0), 1e-10);
        }

        TEST_METHOD(TestAllMethodsN10)
        {
            double expected = 4.987556898505754;

            Assert::AreEqual(expected, S0(1, 10), 1e-10);
            Assert::AreEqual(expected, S1(1, 10, 1), 1e-10);
            Assert::AreEqual(expected, S2(1, 10, 10), 1e-10);
            Assert::AreEqual(expected, S3(1, 10, 1, 0), 1e-10);
            Assert::AreEqual(expected, S4(1, 10, 10, 0), 1e-10);
        }
    };
}