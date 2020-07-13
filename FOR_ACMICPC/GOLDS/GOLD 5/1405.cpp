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
int n;
vector<int>cnt;
void move(vector<int>v, vector<vector<int>>chk) {
	pair<int, int> cur = { 0,0 };
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) cur.first++;
		if (v[i] == 1) cur.second++;
		if (v[i] == 2) cur.first--;
		if (v[i] == 3) cur.second--;
		if (chk[cur.first][cur.second] == 1) {
			return;
		}
		chk[cur.first][cur.second] = 1;
		cnt[v[i]]++;
	}
}
void split(int idx, vector<int>v, vector<vector<int>>chk, int lim) {
	if (v.size() == lim) { move(v,chk); return; }

		for (int i = idx; i < n;i++) {
			for (int f = 0; f < 4; f++) {
				v.push_back(f);
				split(i + 1, v, chk, lim);
				v.pop_back();
			}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int>dir;
	vector<vector<int>>chk;
	chk.assign(29, vector<int>(29, 0));
	cnt.assign(4, 0);
	for (int i = 1; i <= n; i++) {
		split(0, dir, chk, i);
	}
	cout << cnt[0] << cnt[1] << cnt[2] << cnt[3];
}