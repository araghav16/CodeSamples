// UnitTest_FizzBuzzGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

// This header file defines the public API for Google Test.
//It should be included by any test program that uses Google Test.
#include "gtest/gtest.h"

#include "..\FizzBuzzGame\FizzBuzzGame.h"
//#include "..\FizzBuzzGame\FizzBuzzGame.cpp"

/* TEST(test_case_name, test_name) is a predefined macro. 
   These are ordinary C++ functions that don't return a value. 
   In this function, along with any valid C++ statements you want to include, 
   use the various Google Test assertions to check values. 
   The test's result is determined by the assertions; 
   if any assertion in the test fails (either fatally or non-fatally), 
   or if the test crashes, the entire test fails. Otherwise, it succeeds.
*/

/*
** Test to run example provided (inputs from 1 to 36)
*/
TEST(testFizzBuzzGame, TestSpecExample)
{
	FizzBuzzGame game;

	EXPECT_EQ("1"			, game.checkIfFizzBuzz(1));
	EXPECT_EQ("2"			, game.checkIfFizzBuzz(2));
	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(3));
	EXPECT_EQ("4"			, game.checkIfFizzBuzz(4));
	EXPECT_EQ("Buzz"		, game.checkIfFizzBuzz(5));

	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(6));
	EXPECT_EQ("7"			, game.checkIfFizzBuzz(7));
	EXPECT_EQ("8"			, game.checkIfFizzBuzz(8));
	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(9));
	EXPECT_EQ("Buzz"		, game.checkIfFizzBuzz(10));

	EXPECT_EQ("11"			, game.checkIfFizzBuzz(11));
	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(12));
	EXPECT_EQ("13"			, game.checkIfFizzBuzz(13));
	EXPECT_EQ("14"			, game.checkIfFizzBuzz(14));
	EXPECT_EQ("Fizz Buzz"	, game.checkIfFizzBuzz(15));

	EXPECT_EQ("16"			, game.checkIfFizzBuzz(16));
	EXPECT_EQ("17"			, game.checkIfFizzBuzz(17));
	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(18));
	EXPECT_EQ("19"			, game.checkIfFizzBuzz(19));
	EXPECT_EQ("Buzz"		, game.checkIfFizzBuzz(20));

	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(21));
	EXPECT_EQ("22"			, game.checkIfFizzBuzz(22));
	EXPECT_EQ("23"			, game.checkIfFizzBuzz(23));
	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(24));
	EXPECT_EQ("Buzz"		, game.checkIfFizzBuzz(25));

	EXPECT_EQ("26"			, game.checkIfFizzBuzz(26));
	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(27));
	EXPECT_EQ("28"			, game.checkIfFizzBuzz(28));
	EXPECT_EQ("29"			, game.checkIfFizzBuzz(29));
	EXPECT_EQ("Fizz Buzz"	, game.checkIfFizzBuzz(30));

	EXPECT_EQ("31"			, game.checkIfFizzBuzz(31));
	EXPECT_EQ("32"			, game.checkIfFizzBuzz(32));
	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(33));
	EXPECT_EQ("34"			, game.checkIfFizzBuzz(34));
	EXPECT_EQ("Buzz"		, game.checkIfFizzBuzz(35));

	EXPECT_EQ("Fizz"		, game.checkIfFizzBuzz(36));
}

/*
** Test corner cases such as -ve numbers, floats etc
*/
TEST(testFizzBuzzGame, TestCornerCases)
{
	FizzBuzzGame game;
	
	EXPECT_EQ("ERROR"	, game.checkIfFizzBuzz(-5));
	EXPECT_EQ("ERROR"	, game.checkIfFizzBuzz(-2.5));
	EXPECT_EQ("ERROR"	, game.checkIfFizzBuzz(0));
	EXPECT_EQ("ERROR"	, game.checkIfFizzBuzz(0.5));
	EXPECT_EQ("1"		, game.checkIfFizzBuzz(1));
	EXPECT_EQ("ERROR"	, game.checkIfFizzBuzz(2.5));
	EXPECT_EQ("Buzz"	, game.checkIfFizzBuzz(5));
	EXPECT_EQ("Buzz"	, game.checkIfFizzBuzz(100000));
}

/*
** Test checkifnatural method
*/
TEST(testFizzBuzzGame, TestCheckIfNatural)
{
	FizzBuzzGame game;
	EXPECT_EQ(false	, game.checkifnatural(0));
	EXPECT_EQ(false	, game.checkifnatural(-1.2));
	EXPECT_EQ(false	, game.checkifnatural(-1));
	EXPECT_EQ(false	, game.checkifnatural(1.5));
	EXPECT_EQ(false	, game.checkifnatural(-50));

	EXPECT_EQ(true	, game.checkifnatural(1));
	EXPECT_EQ(true	, game.checkifnatural(50));
	EXPECT_EQ(true	, game.checkifnatural(5));
	EXPECT_EQ(true	, game.checkifnatural(1.0));
}

/*
** Test divisibleby3 method
*/
TEST(testFizzBuzzGame, TestIfDivisibleBy3)
{
	FizzBuzzGame game;
	EXPECT_EQ(true, game.divisibleby3(3));
	EXPECT_EQ(true, game.divisibleby3(6));
	EXPECT_EQ(true, game.divisibleby3(9));
	EXPECT_EQ(true, game.divisibleby3(12));
	EXPECT_EQ(true, game.divisibleby3(15));

	EXPECT_EQ(false, game.divisibleby3(2));
	EXPECT_EQ(false, game.divisibleby3(5));
	EXPECT_EQ(false, game.divisibleby3(8));
	EXPECT_EQ(false, game.divisibleby3(11));
	EXPECT_EQ(false, game.divisibleby3(14));
}

/*
** Test divisibleby5 method
*/
TEST(testFizzBuzzGame, TestIfDivisibleBy5)
{
	FizzBuzzGame game;
	EXPECT_EQ(true, game.divisibleby5(5));
	EXPECT_EQ(true, game.divisibleby5(10));
	EXPECT_EQ(true, game.divisibleby5(15));

	EXPECT_EQ(false, game.divisibleby5(7));
	EXPECT_EQ(false, game.divisibleby5(12));
	EXPECT_EQ(false, game.divisibleby5(17));
}

/*
** Test divisibleby15 method
*/
TEST(testFizzBuzzGame, TestIfDivisibleBy15)
{
	FizzBuzzGame game;
	EXPECT_EQ(true, game.divisibleby15(15));
	EXPECT_EQ(true, game.divisibleby15(30));
	EXPECT_EQ(true, game.divisibleby15(45));

	EXPECT_EQ(false, game.divisibleby15(11));
	EXPECT_EQ(false, game.divisibleby15(33));
	EXPECT_EQ(false, game.divisibleby15(44));
}

int _tmain(int argc, _TCHAR* argv[])
{
   /*The method is initializes the Google framework and must be called before RUN_ALL_TESTS */
   ::testing::InitGoogleTest(&argc, argv);

   /*RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro. 
   It's must be called only once in the code because multiple calls lead to conflicts and, 
   therefore, are not supported.
   */ 
   return RUN_ALL_TESTS();
}