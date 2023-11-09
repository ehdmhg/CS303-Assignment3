# CS303-Assignment3
CS303-Assignment3
Part 1
1. The program will ask you to put in a infix expression which will check if the expression inputted by the user is valid and has balanced partheses or grouping. If it is valid, it takes the string and establishes what part of the expression is an opreand and opreator before printing out the postfix expression. For example, the expression "(1+2) - 3 * (4/5) - 6" will output 12+345/*-6- as the conversion from infix to postfix.

Part 2
2. After the infix to postfix conversion, the program will begin testing the functions for the queue. First, it will be created and the numbers (2,6, and 7) are added to the queue via the enqueue function. It will then test the size of the queue after the numbers are added. It will then print the first element of the queue which is found by testing the peek function. The program will then remove the first element by the deque function since Queues follow First in First Out. After the function has been tested, it will print the size of the queue to ensure that removal was sucessful and the size has decreased. Then, the program will enqueue another number before peeking into the queue again and printing out the first element(in this case, it will be 6). After peeking, the program will then check if the queue is emptyt throught the isEmpty function which prints out "No" and the program ends. 
