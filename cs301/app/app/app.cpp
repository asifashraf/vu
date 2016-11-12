// app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main(int argc, char *argv[])
{
	string msg = "--- simple array iteration ---";

	int x[6];

	int i;

	cout << msg << endl;

	for (i = 0; i < 6; i++)
	{
		x[i] = 2 * i;
		
		cout << "Hello World " << i << endl;
		
		// 3

	}




	system("PAUSE");

	return EXIT_SUCCESS;
}


