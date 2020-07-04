#include <iostream>
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
using longs = long long;
vector<int>vec[1001];
bool checker[1001] = { 0 };
int ctr = 0;

void dfs(int n) {
	if (checker[n]) return;
	checker[n] = 1, ctr++;

	for (int i = 0; i < vec[n].size(); i++) {
		ctr++;
		dfs(vec[n][i]);
	}
}

int main() {
	int n, m, input1, input2, firsttry, counter = 0;
	cin >> n >> m;
	for (int f = 0; f < m; f++) {
		cin >> input1 >> input2;
		vec[input1].push_back(input2);
		vec[input2].push_back(input1);
	}

	for (int i = 1; i <= n; i++)
		sort(vec[i].begin(), vec[i].end());

	for (int i = 1; i <= n; i++) {
		if (checker[i] == 0) {
			counter++;
			dfs(i);
		}
	}
	cout << counter;
}