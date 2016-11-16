#pragma once
using namespace std;

class FizzBuzzGame 
{
public:
	/*
	** Main method for this game which calls other methods to check if input is natural number and > 0.
	** Then by calling various other divisibleby methods it decides and prints appropiate "Fizz" and "Buzz".
	*/
	string checkIfFizzBuzz(double input)
	{
		if (checkifnatural(input))
		{
			int inputInt = input; //conversion of natural number from double to int
			if (divisibleby15(inputInt))
			{
				return "Fizz Buzz";
			}
			else if (divisibleby3(inputInt))
			{
				return "Fizz";
			}
			else if (divisibleby5(inputInt))
			{
				return "Buzz";
			}
			else
			{
				return to_string(inputInt);
			}
		}
		else
		{
			//ERROR - invalid input
			return "ERROR";
		}
	}

	/*
	** Check if input is a natural number and > 0.
	*/
	bool checkifnatural(double input)
	{
		//
		if (input <= 0)
		{
			return false;
		}

		if (floor(input) == input)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool divisibleby3(int input)
	{
		if (input % 3 == 0)
			return true;
		return false;
	}

	bool divisibleby5(int input)
	{
		if (input % 5 == 0)
			return true;
		return false;
	}

	bool divisibleby15(int input)
	{
		if (input % 15 == 0)
			return true;
		return false;
	}
};