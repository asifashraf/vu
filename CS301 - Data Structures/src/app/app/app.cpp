// app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
#pragma region print functions

void _pint(string msg, int * value)
{
	cout << msg << ": " << value << endl;
}

void _int(string msg, int value)
{
	cout << msg << ": " << value << endl;
}

void _string(string msg, string value)
{
	cout << msg << ": " << value << endl;
}

#pragma endregion

#pragma region Lecture01

void Lecture01_01_Array()
{
	string msg = "--- simple array iteration ---";

	int x[6];

	_pint("int x[6];", x);

	int i;

	cout << msg << endl;

	for (i = 0; i < 6; i++)
	{
		x[i] = 2 * i;

		_int("x loop value ", x[i]);


	}


	//-------------------
	int * y = new int[20];

	_pint("int * y = new int[20];", y);

	y = &x[0];

	_pint("y = &x[0];", y);

	y = x;
	
	_pint("y = x;", y);


	//-------------------
	int * z = new int[20];

	z[0] = 20;

	_int("z[0] ", z[0]);

	for (i = 0; i < 20; i++)
	{
		z[i] = 5 * i;

		_int("z[i] = 5 * i; ", z[i]);


	}
}



#pragma endregion

int main(int argc, char *argv[])
{

	Lecture01_01_Array();

	system("PAUSE");

	return EXIT_SUCCESS;

}