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
vector <int> vec[1001];
queue <int> q;
bool checker[1001] = { 0 };

void DFS(int num) {
	if (checker[num] == 1) return;

	cout << num << " ";
	checker[num] = 1;
	for (int i = 0; i < vec[num].size(); i++)
		DFS(vec[num][i]);
}



void BFS(int num) {
	bool checker[1001] = { 0 };
	q.push(num);
	checker[num] = 1;

	while (!q.empty()) {
		int x = q.
			();
		cout << x << " ";
		q.pop();
		for (int i = 0; i < vec[x].size(); i++)
			if (checker[vec[x][i]] == 0) {
				q.push(vec[x][i]);
				checker[vec[x][i]] = 1;
			}
	}
}

int main(void) {
	int N, M, input1, input2, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> input1 >> input2;
		vec[input1].push_back(input2);
		vec[input2].push_back(input1);
	}

	for (int i = 1; i < 1001; i++)
		sort(begin(vec[i]), end(vec[i]));

	DFS(V);
	cout << "\n";
	BFS(V);
}