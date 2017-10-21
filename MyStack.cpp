//MyStack.cpp : Implementations of class:'MyStack'
#include "MyStack.h"
#include <iostream>
using std::cout;
using std::endl;
#define INIT_SIZE  20

//Constructor
MyStack::MyStack()
	:top(-1)
	, capacity(INIT_SIZE)
{
	stack = new int[capacity];
}


//private operations
/*
	Enlarge the capacity.

	Return:void
*/
void MyStack::_enlarge()
{
	int* newStack = new int[capacity * 2];
	for (int i = 0; i <= top; i++)
	{
		newStack[i] = stack[i];
	}
	stack = newStack;
	delete[]newStack;
}

//public operations
/*
	Push in an element at top.

	Parameter:num	int		The element.

	Return:void
*/
void MyStack::push(int num)
{
	if (top == (capacity - 1))
	{
		_enlarge();
	}
	else
	{
		stack[++top] = num;
	}
}

/*
	Pop out an element at top.

	Return:int	The element that poped.
*/
int MyStack::pop()
{
	if (top == -1)
	{
		cout << "Stack empty";
		return INT_MIN;
	}
	else
	{

		top--;
		return stack[top + 1];
	}
}

/*
	Print a stack from top to bottom.

	Return:void
*/
void MyStack::print()
{
	for (int i = top; i >= 0; i--)
	{
		cout << stack[i] << "  ";
	}
	cout << endl;
}

/*
	Spilt a stack into two stacks.

	Return:type:'StackPair'	A pair of Mystacks.
*/
StackPair MyStack::split()
{
	int halfSize = (top + 1) / 2;
	MyStack first;
	MyStack second; 
	int i = 0;
	
	for (; i < halfSize; i++)
	{
		first.push(stack[i]);
	}
	for (; i <= top; i++)
	{
		second.push(stack[i]);
	}

	return pair<MyStack, MyStack>(first, second);
}

/*
	Merge two stacks into one.

	Parameter:another	class:'MyStack'		Another stack.

	Return:class:'MyStack'	 Merged stack.
*/
MyStack MyStack::merge(MyStack &another)
{
	MyStack result;
	for (int i = 0; i <= top; i++)
	{
		result.push(stack[i]);
	}
	for (int j = 0; j <= another.top; j++)
	{
		result.push(another.stack[j]);
	}
	return result;
}

/*
	Get current size of stack.

	Return:int	Size of stack.
*/
int MyStack::size()
{
	return top + 1;
}