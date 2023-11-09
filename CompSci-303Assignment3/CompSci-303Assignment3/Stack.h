#pragma once
#include <string>
using namespace std;

template <typename T> //used if data is an int, string, float, etc
class Stack {
private:
	T data[100];
	int top;

public:
	Stack();
	void push(T value);
	T pop();
	T peek();
	bool isEmpty();
};

bool isOperand(char ch);
bool isOperator(char ch);
int preced(char op);
string infixToPost(string exp);
bool isBalanced(string exp);