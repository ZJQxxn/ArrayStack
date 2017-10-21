//MyStack.h : Declaretion of class:'MyStack'
#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
using std::pair;

class MyStack;
typedef pair<MyStack, MyStack> StackPair;

//see implementation in MyStack.cpp
class MyStack
{
private:
	int top;
	int capacity;
	int* stack;
	void _enlarge();
public:
	MyStack();
	void push(int);
	int pop();
	void print();
	int size();
	StackPair split();
	MyStack merge(MyStack&);
};

#endif