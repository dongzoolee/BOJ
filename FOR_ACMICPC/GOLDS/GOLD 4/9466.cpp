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
using ll = long long;
int arr[100001];
int n, sum = 0;
bool bol = 0;
void team(bool chk[], int idx, int hocul, int cnt, int v[]) {
	if (v[idx] != 0 && hocul != idx) { chk[idx] = 1; sum += v[hocul] - v[idx] + 1; bol = 1; return; }

	if (chk[idx] == 0) {
		chk[idx] = 1;
		v[idx] += cnt + 1;
		team(chk, arr[idx], idx, cnt + 1, v);
		//if (bol == 0)
			//chk[idx] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		sum = 0;
		cin >> n;
		for (int f = 1; f <= n; f++)
			cin >> arr[f];
		bool chk[100001] = { 0 };
		for (int i = 1; i <= n; i++) {
			if (arr[i] == i) { chk[i] = 1; sum++; continue; }
			if (chk[i] == 0) {
				chk[i] = 1; // 실패할경우 남겨놓는다. 성공할경우에도 남겨놓는다.
				int v[100001] = { 0 };
				v[i]++;
				team(chk, arr[i], i, 1, v);
				bol = 0;
			}
		}
		cout << n - sum << '\n';
	}
}