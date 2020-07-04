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
int arr[21], goal_sum, counter = 0, tc;

void count(int cur, int sum) {
	if (cur == tc)
		return;

	sum += arr[cur];
	// 원소 하나도 없는 경우 포함 X
	if (sum == goal_sum)
		counter++;
	if (sum > goal_sum)
		if(arr[cur]>=0)
			return;
	// ↑↑↑↑↑↑얘가 왜 오답 조건이지?????????????
	// https://js1jj2sk3.tistory.com/89
	count(cur + 1, sum);
	count(cur + 1, sum - arr[cur]);
}

void dfs(int i, int sum) {
	if (i == tc) return;
	if (sum + arr[i] == goal_sum) counter++;

	dfs(i + 1, sum);
	dfs(i + 1, sum + arr[i]);
}

int main() {
	cin >> tc >> goal_sum;
	for (int i = 0; i < tc; i++)
		cin >> arr[i];
	sort(arr, arr + tc);

	count(0, 0);
	cout << counter;
}