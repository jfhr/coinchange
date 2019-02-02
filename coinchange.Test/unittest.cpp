#include "stdafx.h"
#include <iostream>
#include <chrono>
#include "CppUnitTest.h"
#include "../coinchange/coinchange.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define ENABLE_TRACE
#ifdef ENABLE_TRACE
#  ifdef _MSC_VER
#    include <windows.h>
#    include <sstream>
#    define TRACE(x)                              \
     do {  std::stringstream s;  s << x;          \
           Logger::WriteMessage(s.str().c_str()); \
        } while(0)
#  else
#    include <iostream>
#    define TRACE(x)  std::clog << (x)
#  endif        // or std::cerr << (x) << std::flush
#else
#  define TRACE(x)
#endif


namespace coinchangeTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(AccuracyTest)
		{
			// Arrange
			const int sum = 200;
			const int* firstcoin = new int[8]{ 200, 100, 50, 20, 10, 5, 2, 1 };
			const int* lastcoin = firstcoin + 7;
			const int expected = 73682;

			// Act
			int actual = coinchange(sum, firstcoin, lastcoin);

			// Assert
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(AccuracyTest_ReverseCoinOrder)
		{
			// Arrange
			const int sum = 200;
			const int* firstcoin = new int[8]{ 1, 2, 5, 10, 20, 50, 100, 200 };
			const int* lastcoin = firstcoin + 7;
			const int expected = 73682;

			// Act
			int actual = coinchange(sum, firstcoin, lastcoin);

			// Assert
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(AccuracyTest_WeirdCoinOrder)
		{
			// Arrange
			const int sum = 200;
			const int* firstcoin = new int[8]{ 5, 200, 1, 20, 100, 2, 50, 10 };
			const int* lastcoin = firstcoin + 7;
			const int expected = 73682;

			// Act
			int actual = coinchange(sum, firstcoin, lastcoin);

			// Assert
			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(PerformanceTest)
		{
			// Arrange
			const int sum = 200;
			const int* firstcoin = new int[8]{ 200, 100, 50, 20, 10, 5, 2, 1 };
			const int* lastcoin = firstcoin + 7;
		    
			// Act
			auto start = std::chrono::high_resolution_clock::now();
			int actual = coinchange(sum, firstcoin, lastcoin);
			auto end = std::chrono::high_resolution_clock::now();

			// Assert
			auto interval = end - start;
			double ns = interval.count();
			double ms = ns / 1000 / 1000;

			TRACE("Performance test complete. Took " << ns << " ns, or " << ms << " ms");
		}

	};
}
