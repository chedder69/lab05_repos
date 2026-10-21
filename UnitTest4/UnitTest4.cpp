#include "pch.h"
#include "CppUnitTest.h"
#include "../PR5.3/PR5.3.cpp" 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5_3_Tests
{
    TEST_CLASS(FunctionTests)
    {
    public:

        TEST_METHOD(TestSeriesZero)
        {
            Assert::AreEqual(
                0.0, f(0.0), 1e-10);
        }

        TEST_METHOD(TestSeriesPositive)
        {
            Assert::AreEqual(
                0.252612316808168,
                f(0.5),
                1e-10);
        }

        TEST_METHOD(TestSeriesNegative)
        {
            Assert::AreEqual(
                0.252612316808168,
                f(-0.5),
                1e-10);
        }

        TEST_METHOD(TestTrigonometric)
        {
            Assert::AreEqual(
                1.684578724360494,
                f(1.0),
                1e-10);
        }

        TEST_METHOD(TestZZero)
        {
            Assert::AreEqual(
                2.837805478568028,
                calculateZ(0.0),
                1e-10);
        }

        TEST_METHOD(TestZPositive)
        {
            Assert::AreEqual(
                4.009164125730742,
                calculateZ(0.5),
                1e-10);
        }

        TEST_METHOD(TestZNegative)
        {
            Assert::AreEqual(
                2.159534911062785,
                calculateZ(-0.5),
                1e-10);
        }
    };
}