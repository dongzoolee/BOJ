// https://blog.myungwoo.kr/112
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
vector<pair<int, int>>v[100001];
int chk[100001];
int mlen = 0, midx;
void dfs(int idx, int len) {
	if (mlen < len) {
		mlen = len;
		midx = idx;
	}

	for (int i = 0; i < v[idx].size(); i++) {
		if (chk[v[idx][i].first])continue;

		chk[v[idx][i].first] = 1;
		dfs(v[idx][i].first, len + v[idx][i].second);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		cin >> b;
		while (1) {
			cin >> a;
			if (a == -1) break;
			cin >> c;
			v[a].push_back({ b ,c });
			v[b].push_back({ a,c });
		}
	}
	chk[1] = 1;
	dfs(1, 0);
	memset(chk, 0, sizeof(chk));
	chk[midx] = 1;
	dfs(midx, 0);
	cout << mlen;
}