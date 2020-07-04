#include <iostream>
#include <stdio.h>
#include <string>
#include <malloc.h>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <limits.h>
#define Q_SIZE 100
using namespace std;

typedef int element; // せせせせせせせ戚薦 int虞 照床壱 element稽 床檎 喫.
element queue[Q_SIZE], counter = 0;

int enqueue(int front, int* rear, element to_insert) {
	*rear = (*rear + 1) % Q_SIZE;
	if (front == *rear)
		cout << "FULL QUEUE !";
	else {
		counter++;
		queue[*rear] = to_insert;
	}
}

int dequeue(int* front, int rear) {
	if (*front == rear)
		cout << "EMPTY QUEUE !";
	else {
		counter--;
		*front = (*front + 1) % Q_SIZE;
		cout << queue[*front];
	}
}

int main() {
	int rear = 0, front = 0;

	//ENQUEUE

	//DEQUEUE

	//PRINT QUEUEs
	for (int i = 1; i <= counter; i++)
		cout << queue[(front + i) & Q_SIZE];

}