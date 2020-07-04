#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <limits.h>
using namespace std;
int queue[10000000];
int head = 0, tail = -1;		// 맨 처음엔 큐 원소 개수가 하나이므로 head와 tail은 0으로 같다.

void queue_input(int num) {
	for (int i = 1; i <= num; i++)
		queue[++tail] = i;	// ENQUEUE할 때마다 tail에 값을 넣고 증가시킨다.
}

void enqueue(int num) {
	//ENQUEUE
	queue[++tail] = num;	// ENQUEUE할 때마다 tail에 값을 넣고 증가시킨다.
}

void dequeue(int num) {
	//DEQUEUE
	if (tail != 0)
		head++;	// 나 이거 뺀다 & head를 증가 근데 input이 1인 case 제외
	else
		return;
}

void to_tail() {
	queue[tail + 1] = queue[head];
	tail++;
	head++;
}

int main() {
	int input;
	cin >> input;

	queue_input(input);

	while (12) {
		dequeue(head);
		if (head != tail)
			to_tail();
		else {
			cout << queue[tail];
			break;
		}
	}
}