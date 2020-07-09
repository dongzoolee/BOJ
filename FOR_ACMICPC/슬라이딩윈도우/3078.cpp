#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
int name_len[21] = { 0 };
vector <int> vec;

int main(void) {
	long long N, K, z = 0, temp, counter = 0;
	string str;
	cin >> N >> K;
	queue <int> q;
	for (int i = 0; i < N; i++) {
		cin >> str
		vec.push_back(str.length());
		if (i <= K) {
			q.push(vec[i]);
			name_len[vec[i]]++;
		}
	}

	for (int i = 0; i < N - K - 1; i++) {
		counter += name_len[q.front()] - 1;
		name_len[q.front()]--;
		q.pop();
		q.push(vec[i + K + 1]);
		name_len[vec[i + K + 1]]++;
	}
	for (int i = N - K - 1; i < N - 1; i++) {
		counter += name_len[q.front()] - 1;
		name_len[q.front()]--;
		q.pop();
	}
	cout << counter;
}