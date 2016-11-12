// app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
#pragma region print functions
void _pint(string msg, int * value)
{
	cout << "x " << value << endl;
}
void _int(string msg, int value)
{
	cout << "x " << value << endl;
}
void _string(string msg, string value)
{
	cout << "x " << value << endl;
}
#pragma endregion

int L01_02_List(int argc, char *argv[])
{
	string msg = "--- simple array iteration ---";

	int x[6];

	_pint("x", x);

	int i;

	cout << msg << endl;

	for (i = 0; i < 6; i++)
	{
		x[i] = 2 * i;

		_int("x loop value ", x[i]);


	}

	int* y = new int[20];
	y = &x[0];
	y = x;
	system("PAUSE");

	return EXIT_SUCCESS;
}

