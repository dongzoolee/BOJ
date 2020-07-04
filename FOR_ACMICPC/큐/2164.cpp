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
int head = 0, tail = -1;		// �� ó���� ť ���� ������ �ϳ��̹Ƿ� head�� tail�� 0���� ����.

void queue_input(int num) {
	for (int i = 1; i <= num; i++)
		queue[++tail] = i;	// ENQUEUE�� ������ tail�� ���� �ְ� ������Ų��.
}

void enqueue(int num) {
	//ENQUEUE
	queue[++tail] = num;	// ENQUEUE�� ������ tail�� ���� �ְ� ������Ų��.
}

void dequeue(int num) {
	//DEQUEUE
	if (tail != 0)
		head++;	// �� �̰� ���� & head�� ���� �ٵ� input�� 1�� case ����
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