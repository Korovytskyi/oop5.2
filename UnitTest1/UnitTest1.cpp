#include "pch.h"
#include "CppUnitTest.h"
#include "../oop5.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Time T;
			Assert::AreEqual(T.Time1(2, 6, 5, 1, 2, 2), 3845);
		}
	};
}