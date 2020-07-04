#include <stdio.h>
#include <iostream>
#define size 10000
using namespace std;
int top = -1;
int stack[size];

void push(int n) {		  
	if (top >= size - 1)
		cout << "overflow\n";
	else
		stack[++top] = n;
}

void pop() {
	if (top < 0)
		cout << "empty";
	else
		cout << stack[top--] << "\n";
}

void print_stack() {
	for (int i = 0; i <= top; i++)
		cout << stack[i];
	cout << "\n";
}

int main() {
	push(5);
	push(4);
	push(6);
	push(3);
	print_stack();
	pop();
	pop();
	print_stack();
}