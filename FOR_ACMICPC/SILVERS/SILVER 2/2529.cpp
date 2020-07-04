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
long long k, min_ = LLONG_MAX, max_ = 0;
char bud[10];

void dfs(long long cur_f, long long cur_i, queue<long long>q, vector<bool>arr) {
	if (cur_f >= 10 || cur_i > k) return;
	q.push(cur_f);
	arr[cur_f] = 1;

	if (bud[cur_i] == '<') {
		for (long long i = cur_f + 1; i < 10; i++)
			if (arr[i] == 0)
				dfs(i, cur_i + 1, q, arr);
	}
	else if (bud[cur_i] == '>') {
		for (long long i = cur_f - 1; i >= 0; i--)
			if (arr[i] == 0)
				dfs(i, cur_i + 1, q, arr);
	}

	if (q.size() == k + 1) {
		long long temp = 0, k_ = k;
		while (q.size() != 0) {
			temp += (long long)pow(10, k_--) * q.front();
			q.pop();
		}
		min_ = min(temp, min_);
		max_ = max(temp, max_);
	}
	else
		return;
}

int main() {
	cin >> k;
	for (long long i = 0; i < k; i++)
		cin >> bud[i];
	vector<bool> bol(10, 0);
	queue<long long>qu;
	for (long long i = 0; i < 10; i++)
		dfs(i, 0, qu, bol);

	if ((long long)log10(max_) + 1 != k + 1) {
		cout << "0";
		cout << max_;
		cout << "\n";
	}
	else if ((long long)log10(max_) + 1 == k + 1) {
		cout << max_;
		cout << "\n";
	}

	if ((long long)log10(min_) + 1 != k + 1) {
		cout << "0";
		cout << min_;
	}
	else if ((long long)log10(min_) + 1 == k + 1) {
		cout << min_;
	}
}