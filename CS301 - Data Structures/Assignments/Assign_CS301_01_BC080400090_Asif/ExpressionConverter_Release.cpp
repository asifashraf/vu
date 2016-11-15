#include<iostream>
#include<stack>
#include<string>

using namespace std;

//Solution by: BC080400090

class ExpressionConverter
{

public:

	string FromInToPost(string str);

private:

	int isOperatorMoreImportant(char operator1, char operator2);
	bool isCharAMathOperator(char charact);
	bool isCharAlphaNumeric(char charact);
	int getOperatorsLevel(char opertr);

};

int ExpressionConverter::isOperatorMoreImportant(char op1, char op2)
{
	int l1 = getOperatorsLevel(op1);
	int l2 = getOperatorsLevel(op2);

	if (l1 == l2)
	{
		return true;
	}
	return l1 > l2 ? true : false;

}

string ExpressionConverter::FromInToPost(string str)
{
	string result = "";

	stack<char> stk;

	size_t countChars = str.length();

	for (int i = 0; i < countChars; i++)
	{
		char currentChar = str[i];
		
		
		//variable?
		if (isCharAlphaNumeric(currentChar))
		{
			result += currentChar;
			continue;
		}

		//operator?
		if (isCharAMathOperator(currentChar))
		{
			while (!stk.empty() && stk.top() != '(' && isOperatorMoreImportant(stk.top(), currentChar))
			{
				result += stk.top();
				stk.pop();
			}

			stk.push(currentChar);

			continue;
		}

		//braces?
		if (currentChar == '(')
		{
			stk.push(currentChar);
			continue;
		}

		if (currentChar == ')')
		{
			while (!stk.empty() && stk.top() != '(')
			{
				result += stk.top();

				stk.pop();
			}

			stk.pop();

			continue;
		}

		
	}

	while (!stk.empty())
	{
		result += stk.top();

		stk.pop();
	}

	return result;
}

bool ExpressionConverter::isCharAlphaNumeric(char charact)
{
	return
		((charact >= '0' && charact <= '9') ||
		(charact >= 'a' && charact <= 'z') ||
			(charact >= 'A' && charact <= 'Z'));

}

bool ExpressionConverter::isCharAMathOperator(char charact)
{
	return (charact == '+' || charact == '-' || charact == '*' || charact == '/');
}

int ExpressionConverter::getOperatorsLevel(char opertr)
{
	if (opertr == '+' || opertr == '-')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int main()
{
	ExpressionConverter converter;

	std::string expression = "A+B*C/(D-B)";

	std::string postfix = converter.FromInToPost(expression);

	std::cout << "Output = " << postfix << "\n";

	std::cin.get();

	return 0;

}