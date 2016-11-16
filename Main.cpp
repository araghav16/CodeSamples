// FizzBuzzGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FizzBuzzGame.h"

int _tmain(int argc, _TCHAR* argv[])
{
	FizzBuzzGame game;

	for (int i = 1; i < 37; i++)
	{
		cout << game.checkIfFizzBuzz(i) << ", ";
	}
	cout << endl;

	return 0;
}

