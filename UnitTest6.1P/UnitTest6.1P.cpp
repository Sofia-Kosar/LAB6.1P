#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB6.1P/LAB6.1P.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61P
{
	TEST_CLASS(UnitTest61P)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 5;
			int a[size] = { 1, 3, 6, 15, 26 };
			double z = Sum(a, 3, 0, 0);
			Assert::AreEqual(z, 3.0);
		}
	};
}
