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
#include<numeric>
using namespace std;
using ll = long long;
vector<int>vec[10001];
int dep[10001];
vector<int> lv_by_dep[10001];
int xdim[10001];
int par[10001];
int n, cnt = 1, max_dep = 0, parent;
void bfs() {
	queue<pair<int, int>>q;
	//		  idx  깊이
	q.push({ parent,1 });
	lv_by_dep[1].push_back(1);
	while (!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (vec[cur].size() && vec[cur][0] > 0) {
			q.push({ vec[cur][0], depth + 1 });
			dep[vec[cur][0]] = depth + 1;
			lv_by_dep[depth + 1].push_back(vec[cur][0]);
		}
		if (vec[cur].size() && vec[cur][1] > 0) {
			q.push({ vec[cur][1], depth + 1 });
			dep[vec[cur][1]] = depth + 1;
			lv_by_dep[depth + 1].push_back(vec[cur][1]);
		}
		max_dep = max(max_dep, depth);
	}
}

void jung(int idx) {
	// 왼쪽 노드
	if (vec[idx].size() && vec[idx][0] > 0)
		jung(vec[idx][0]);
	// 자신
	xdim[idx] = cnt++;
	// 오른쪽 노드
	if (vec[idx].size() && vec[idx][1] > 0)
		jung(vec[idx][1]);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		par[b] = a, par[c] = a;
		vec[a].push_back(b);
		vec[a].push_back(c);
	}
	// 루트 찾기
	for (int i = 1; i <= n; i++)
		if (par[i] == 0)
			parent = i;
	// 깊이 찾기
	dep[parent] = 1;
	bfs();
	// x값 찾기
	jung(parent);
	// 너비 긴거 찾기
	int max_len = 0;
	int lev;
	for (int i = 1; i <= max_dep; i++) {
		if (lv_by_dep[i].size() > 1) {
			if (xdim[lv_by_dep[i][lv_by_dep[i].size() - 1]] - xdim[lv_by_dep[i][0]] + 1 > max_len) {
				max_len = xdim[lv_by_dep[i][lv_by_dep[i].size() - 1]] - xdim[lv_by_dep[i][0]] + 1;
				lev = i;
			}
		}
		else {
			if (max_len < 1) {
				max_len = 1;
				lev = i;
			}
		}
	}
	cout << lev << ' ' << max_len;
}