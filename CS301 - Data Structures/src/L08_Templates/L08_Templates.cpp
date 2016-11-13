// L08_Templates.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Stack.cpp"

using namespace std;

int main(int argc, char *argv[])
{
	Stack<int> intstack;
	int x = 10, y = 20;
	intstack.push(x);
	intstack.push(y);
	cout << "intstack: " << intstack.pop() << ", " << intstack.pop() << "\n";

	Stack<char> charstack;
	char c = 'C', d = 'D';
	charstack.push(c); 
	charstack.push(d);
	cout << "charstack: " << charstack.pop() << ", " << charstack.pop() << "\n";
	
	system("pause");	
}

