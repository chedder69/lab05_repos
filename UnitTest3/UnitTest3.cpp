#include "pch.h"
#include "CppUnitTest.h"
#include "../PR5.2/PR5.2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5_2_Tests
{
    TEST_CLASS(SeriesTests)
    {
    public:

        TEST_METHOD(TestNextTerm)
        {
            double result = A(2.0, 1, 0.5);

            Assert::AreEqual(
                1.0 / 24.0, result, 0.0000001);
        }

        TEST_METHOD(TestSeriesPositive)
        {
            int n = 0;

            double result = S(2.0, 0.00000001, n);

            Assert::AreEqual(
                0.549306144334, result, 0.0000001);
        }

        TEST_METHOD(TestSeriesNegative)
        {
            int n = 0;

            double result = S(-2.0, 0.00000001, n);

            Assert::AreEqual(
                -0.549306144334, result, 0.0000001);
        }
    };
}