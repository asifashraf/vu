#include "stdafx.h" 

//Core
#include<iostream>
#include<conio.h>

//Needed
#include<string>
#include<stack>


using namespace std;

class Converter {

public:
	string Convert(string expr);

private:
	bool isCharOperand(char arg);
	bool isoperator(char arg);
	int operatorweight(char arg);
	bool highprecendence(char a, char b);
};

string Converter::Convert(string expr)//Function to perform all conversion operation
{

	stack<char> stk;//Declaring a stack for conversion purpose
	string postfix = "";//Initialize the output string as empty;
	for (int i = 0; i < expr.length(); i++)//Scan the infix string one by one
		if (expr[i] == '(')
		{
			stk.push(expr[i]);
		}
		else if (expr[i] == ')')
		{
			while (stk.top() != '(')
			{
				postfix = postfix + stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else if (isCharOperand(expr[i]))
		{
			postfix += expr[i];
		}
		else if (isoperator(expr[i]))
		{
			while (!stk.empty() && !highprecendence(expr[i], stk.top()))
			{
				postfix += stk.top();
				stk.pop();
			}
			stk.push(expr[i]);
		}





	while (!stk.empty())
	{
		postfix += stk.top();
		stk.pop();
	}



	return postfix;
}

bool Converter::isCharOperand(char arg)
{
	return false;
}

bool Converter::highprecendence(char a, char b)//Check for operator precendence
{
	int weighta = operatorweight(a);
	int weightb = operatorweight(b);
	if (weighta >= weightb) return 1;
	return 0;
}

bool Converter::isoperator(char arg)//Check weather the character is operator
{
	if (arg == '*' || arg == '/' || arg == '+' || arg == '-') return(1);
	else return(0);
}

int Converter::operatorweight(char arg)//Add weight to the operator
{
	int weight = 0;
	switch (arg)
	{
	case '*':
	case '/':
		weight = 2;
		break;
	case '+':
	case '-':
		weight = 1;
		break;
	}
	return(weight);

	return 0;
}


int _main()
{
	Converter cnv;

	string testInfixExpression = "A + B * C / (D-B)";

	string resultPostFixExpression = cnv.Convert(testInfixExpression);

	cout << "Result is: ";

	cout << resultPostFixExpression;

	_getch();

	return 0;
}


