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
vector<int>v[2000];
int chk[2000] = { 0 }, n, m, total = 0;

void dfs(int num, int cnt) {
	if (chk[num] == 1)return;
	if (cnt >= 4) { cout << 1; exit(0); }

	chk[num] = 1;
	for (int i = 0; i < v[num].size(); i++)
		dfs(v[num][i], cnt + 1);
	chk[num] = 0; // ....필수
	// 기존 DFS는 그냥 전체 탐색
	// 근데 이 문제는 탐색 중에 계속 새로운 set이 있는지의 여부를 확인해야하므로
	// chk[n]=0을 꼭 해주어야한다.
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < 2000; i++) {
		if (v[i].size() != 0) {
			dfs(i, 0);
		}
	}
	cout << 0;
}