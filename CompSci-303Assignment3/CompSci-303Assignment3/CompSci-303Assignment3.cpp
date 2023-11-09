// CompSci-303Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.h"
#include "Stack.h"
int main()
{
    string infixExp;
    cout << "Enter infix expression: ";
    getline(cin, infixExp);
    if (!isBalanced(infixExp)) {
        cout << "Invalid Expression" << endl;
    }
    else if (infixExp == " " || infixExp == "") {
        cout << "Invalid Expression" << endl;
    }
    else {
        string postfixExp = infixToPost(infixExp);
        cout << "The Postfix expression: " << postfixExp << endl;
    }
    
    
    
    
    Queue testQue;

    testQue.enqueue(2);
    testQue.enqueue(6);
    testQue.enqueue(7);

    //Tests functions for the Queue
    cout << endl << "Current Size of Queue: " << testQue.getSize() << endl; //Outputs 3
    cout << endl << "First Element: " << testQue.peek() << endl; //Outputs 2
    cout << endl << "Removed Element: " << testQue.dequeue() << endl; //Outputs 2 since Queue is (First in First Out)
    cout << endl << "Current Size of Queue: " << testQue.getSize() << endl; //Outputs 2 since the first element was removed

    testQue.enqueue(9); //inserts 9 to the back of the queue

    cout << endl << "First Element: " << testQue.peek() << endl; //Outputs 6;

    cout << endl << "Queue is empty? " << (testQue.isEmpty() ? "Yes" : "No") << endl; //Outputs no since size is 3. 

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
