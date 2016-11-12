#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>

using namespace std;

class c 
{

public:

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

private:


};
