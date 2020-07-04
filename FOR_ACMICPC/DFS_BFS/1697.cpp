//BFS�� ���������κ��� ����� ���̺��� ���� �����Ѵ�.

#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
int depth = 0, end_point;
bool checker[100003] = { 0 };

void BFS(int n) {
	checker[n] = 1;
	queue<int>q;
	q.push(n);

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) { // ���� ���̿� �ִ� ��� ���� ����
			int frt = q.front();
			q.pop();
			// q.front()���� �������.
			if (checker[frt - 1] == 0 && frt >= 1 && frt - 1 <= 100000) {
				q.push(frt - 1);
				checker[frt - 1] = 1;
			}
			if (checker[frt + 1] == 0 && frt + 1 <= 100000) {
				q.push(frt + 1);
				checker[frt + 1] = 1;
			}
			if (2 * frt <= 100000 && checker[2 * frt] == 0) {
				q.push(2 * frt);
				checker[2 * frt] = 1;
			}
			if (frt == end_point)
				return;
		} // end of for
		depth++; // for ���� ������ ���� ����
	} // end of while
}
int main() {
	int N;
	cin >> N >> end_point;

	BFS(N);
	cout << depth;
}