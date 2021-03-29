#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3_3_A/FuzzyNumber_Public.cpp"
#include "../Lab_3_3_A/FuzzyNumber_Private.cpp"
#include "../Lab_3_3_A/FuzzyNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest33A
{
	TEST_CLASS(Labtest33A)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber_Private A1(4, 1, 7), B1(6, 3, 9);
			FuzzyNumber_Private Sum = A1 + B1;
			Assert::AreEqual(Sum.GetX(), 10.0);
		}

		TEST_METHOD(TestMethod2)
		{
			FuzzyNumber_Public A2(6, 3, 9);
			A2++;
			Assert::AreEqual(A2.GetX(), 7.0);
		}
	};
}
