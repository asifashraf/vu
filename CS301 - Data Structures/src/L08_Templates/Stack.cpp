#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "Stack.h"

#define MAXSTACKSIZE 50

template <class T>
Stack<T>::Stack()
{
	top = -1;
	nodes = new T[MAXSTACKSIZE];
}

template <class T>
Stack<T>::~Stack()
{
	delete nodes;
}

template <class T>
int Stack<T>::empty(void)
{
	if (top < 0) return 1;
	return 0;
}

template <class T>
int Stack<T>::push(T & x)
{
	if (top < MAXSTACKSIZE)
	{
		nodes[++top] = x;
		return 1;
	}
	cout << "stack overflow in push.\n";
	return 0;
}
template <class T>
T Stack<T>::pop(void)
{
	T x;
	if (!empty())
	{
		x = nodes[top--];
		return x;
	}
	cout << "stack underflow in pop.\n";
	return NULL;
}