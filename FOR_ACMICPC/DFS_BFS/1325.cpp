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
vector <long long> vec[10001];
bool chk[10001] = { 0 };
long long leaves[10001] = { 0 }, leav_max = 0;

void DFS(long long num, bool* chkr) {
	if (chk[num] == 1 || chkr[num] == 1) return;
	chkr[num] = 1;
	chk[num] = 1;
	for (long longf = 0; f < vec[num].size() && chkr[vec[num][f]] != 1; f++) {
		leaves[num]++;
		DFS(vec[num][f],chkr);
		leaves[num] += leaves[vec[num][f]];
	}
}
long long main() {
	long long N, M, input1, input2;
	cin >> N >> M;
	for (long long i = 0; i < M; i++) {
		cin >> input1 >> input2;
		vec[input2].push_back(input1);
	}

//	for (long long i = 1; i < 10001 && vec[i].size() != 0; i++)
//		sort(begin(vec[i]), end(vec[i]));

	for (long long i = 1; i < 10001 && vec[i].size()!=0; i++) {
		bool chkr[10001] = { 0 };
		DFS(i,chkr);
		leav_max = max(leaves[i], leav_max);
	}

	// 1 2
	//  3
	//  5 5

	for (long long i = 1; i < 10001 && vec[i].size() != 0; i++)
		if (leaves[i] == leav_max)
			cout << i << " ";
}