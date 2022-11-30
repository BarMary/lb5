#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\Documents\хпі\оіпз\lb3\lb3\lb3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlb3
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(calculate_getminus5and10and1and2and0_truereturned)
		{
			double a = -5;
			double b = 10;
			double h = 1;
			int n = 2;
			bool write_to_file = 0;
			int expected = true;
			int actual = calculate(a, b, h, n, write_to_file);
			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(calculate_get0and8and2and3and0_truereturned)
		{
			double a = 0;
			double b = 8;
			double h = 2;
			int n = 3;
			bool write_to_file = 0;
			int expected = true;
			int actual = calculate(a, b, h, n, write_to_file);
			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(checkValidParams_Tests)
	{
	public:
		TEST_METHOD(checkValidParams_get1and4and1and0and0_exceptionThrown)
		{
			double a = 1;
			double b = 4;
			double h = 1;
			int n = 0;
			bool write_to_file = 0;
			try
			{
				checkValidParams(a, b, h, n, write_to_file);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	public:
		TEST_METHOD(checkValidParams_get3and1and4and1and0_exceptionThrown)
		{
			double a = 3;
			double b = 1;
			double h = 4;
			int n = 1;
			bool write_to_file = 0;
			try
			{
				checkValidParams(a, b, h, n, write_to_file);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	public:
		TEST_METHOD(checkValidParams_get3and7andminus1and1and0_exceptionThrown)
		{
			double a = 3;
			double b = 7;
			double h = -1;
			int n = 1;
			bool write_to_file = 0;
			try
			{
				checkValidParams(a, b, h, n, write_to_file);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		};
	};
}
