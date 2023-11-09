#include "Stack.h"
#include <stack>
#include <map>
#include <iostream>
using namespace std;

template <typename T>
Stack<T>::Stack() {
	top = -1;
}

template <typename T>
void Stack<T>::push(T value) {
	if (top < 99) {
		data[+top] = value;
	}
}

template <typename T>
T Stack<T>::pop() {
	if (top >= 0) {
		return data[top--];
	}
	return T();//Returns a default-constructued value IF the stack is empty
}

template <typename T>
T Stack<T>::peek() {
	if (top >= 0) {
		return data[top];
	}
	return T();//Returns a default-constructed value IF the stack is emtpy
}

template <typename T>
bool Stack<T>::isEmpty() {
	return top == -1;
}

bool isOperand(char ch) {
	return (ch >= '0' && ch <= '9'); //checks to see if teh chracter is a opreand
}

bool isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');//checks to see if the character is an opreator
}

//Function to check the order of equation
int preced(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/' || op == '%') {
		return 2;
	}
	else {
		return 0;
	}
}

string infixToPost(string exp) {
	stack<char> st;
	string postfixExp = "";
	char space = ' ';
	for (int i = 0; i < exp.length(); i++) {
		char ch = exp[i];
		//checks to see if the character is an Opreand
		if (isOperand(ch)) {
			postfixExp += ch;
		}
		//checks to see if the character is an Operator
		else if (isOperator(ch)) {
			while (!st.empty() && st.top() != '(' && preced(ch) <= preced(st.top())) {
				postfixExp += st.top();//increment the string
				st.pop();
			}
			st.push(ch);//pushes ch into the stack
		}
		else if (ch == '(') {
			st.push(ch);
		}
		else if (ch == ')') {
			while (!st.empty() && st.top() != '(') {
				postfixExp += st.top();//increment the string
				st.pop(); 
			}
			if (!st.empty() && st.top() == '(') {
				st.pop();
			}
			else {
				return "Expression is not valid";
			}
		}
	}
	while (!st.empty()) {
		if (st.top() == '(' || st.top() == ')') {
			return "Invalid Expression";
		}
		postfixExp += st.top(); //increment the string
		st.pop();
	}
	return postfixExp;
}

bool isBalanced(string exp) {
	stack<char> st;
	for (int i = 0; i < exp.length(); i++) {
		char ch = exp[i];
		if (ch == '{' || ch == '(' || ch == '[') {
			st.push(ch);//pushes ch into the stack
		}
		else if (ch == '}' || ch == ')' || ch == ']') {
			if (st.empty()) {
				return false;
			}
			if ((ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[') || (ch == ')' && st.top() == '(')) {
				st.pop();
			}
			else {
				return false;
			}
		}
	}
	return st.empty();
}
