//main.cpp : Main funtion to test class:'MyStack'
#include "MyStack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	MyStack stack1;
	MyStack stack2;
	//Test print
	for (int i = 0; i < 5; i++)
	{
		stack1.push(i);
	}
	cout << "Stack1 : ";
	stack1.print();
	cout << "Stack1 size:" << stack1.size() << endl;
	for (int i = 10; i < 20; i++)
	{
		stack2.push(i);
	}
	cout << "Stack 2: ";
	stack2.print();
	cout << "Stack2 size:" << stack2.size() << endl;

	cout << "Stack2 pop : " << stack2.pop() << endl;
	cout << "Stack2 pop : " << stack2.pop() << endl;
	cout << "Stack2 after pop: ";
	stack2.print();

	//test split
	StackPair pair = stack2.split();
	cout << "\nStack2 split:\n";
	cout << "first :";
	pair.first.print();
	cout << "second :";
	pair.second.print();

	//test merge
	MyStack mergedStack = stack1.merge(stack2);
	cout << "\nStack1 merge stack2 :";
	mergedStack.print();

	system("pause");
	return 0;
}