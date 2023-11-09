#pragma once
#include <iostream>
using namespace std;

const int max_size = 100; //Sets the max size of the queue at any given time.

class Queue {
private:
	int arr[max_size]; //Array that the Queue will be stored in.
	int front; // Front is the first element of the Queue
	int rear; // Back is the last element of the queue
	int size; //The current size of the queue. 

public:

	Queue() {
		front = rear = -1; //Initalize the front and rear indices to -1
		size = 0; //Initalize current size of the queue to 0.
	}
	
	//Function that inserts a new element at the rear
	void enqueue(int element) {
		//If statement to check if the current size is equal to max_size.
		if (size == max_size) {
			cout << "Queue is full. Unable to insert any more elements." << endl;
			return;
		}

		//increments front for insertion of new element.
		if (front == -1) {
			front++;
		}
		
		//increments rear for insertion of new element.
		rear++;
		arr[rear] = element;
		size++; //increment size to equal current size of the Queue. 
	}
	//Function to remove front element of the queue AND return it. 
	int dequeue() {
		//If statement to check if dequeue is possible
		if (front == -1 || front > rear) {
			cout << "Queue is empty. Cannot apply dequeue to the queue." << endl;
			return -1;
		}

		//If dequeue is possible
		int element = arr[front];
		front++;
		size--;//decrement size due to removal of element

		return element;
	}
	//Function to return front elemetn present without removal
	int peek() {
		//If statement to check if the queue is empty. 
		if (front == -1 || front > rear) {
			cout << "Queue is empty. Unable to peek into Queue." << endl;
			return -1;
		}

		return arr[front];
	}
	//Function to check if the queue is empty.
	bool isEmpty() {
		return (front == -1 || front > rear);
	}
	//Function to return current size of the queue(number of elements present)
	int getSize() {
		return size;
	}
};