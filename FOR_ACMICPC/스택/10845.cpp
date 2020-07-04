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
int queue[10000000], push_counter = 0;
int head = 0, tail = -1;		// �� ó���� ť ���� ������ �ϳ��̹Ƿ� head�� tail�� 0���� ����.
bool ever_pushed = 0, its_empty = 0;

void front() {
	if ((push_counter != 0 && its_empty == 0) || tail - head > 0 || (head == tail && its_empty == 0))
		cout << queue[head] << "\n";
	else
		cout << "-1\n";
}

void back() {
	if ((push_counter != 0 && its_empty == 0) || tail - head > 0 || (head == tail && its_empty == 0))
		cout << queue[tail] << "\n";
	else
		cout << "-1\n";
}

void push(int num) {
	//ENQUEUE
	if (its_empty == 0)
		queue[++tail] = num;	// ENQUEUE�� ������ tail�� ���� �ְ� ������Ų��.
	else {
		queue[tail] = num;
		its_empty = 0;
	}
}

void size() {
	if (tail - head > 0 || (tail == head && its_empty == 0))
		cout << tail - head + 1 << "\n";
	else
		cout << "0\n";
}

void empty() {
	if (tail - head > 0 || (tail == head && its_empty == 0)) // ��	��	��	��	�� 
		cout << "0\n";
	else
		cout << "1\n";
}
void pop() {
	//DEQUEUE
	if (tail - head > 0 || (tail == head && its_empty == 0)) {
		cout << queue[head] << "\n";
		if (head != tail)
			head++;	// �� �̰� ���� & head�� ���� �ٵ� input�� 1�� case ����
		else
			its_empty = 1;
	}
	else
		cout << "-1\n"; // Ȯ	��	��	��	ť	��	��	��	��	��	��	��
}

int main() {
	int tc, n;
	string str;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> str;
		if (str == "push") {
			cin >> n;
			push(n);
			push_counter++;
		}
		if (str == "pop")
			pop();
		if (str == "size")
			size();
		if (str == "empty")
			empty();
		if (str == "front")
			front();
		if (str == "back")
			back();

	}
}