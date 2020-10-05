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
#include <deque>
#include <numeric>
using namespace std;
using ll = long long;
deque<pair<int, int>>v[100001];
int isempty[100001];
int idx1[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int d, h;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> d >> h;
		v[i%m].push_back({ d,h });
	}
	int dec_v = k % m;
	int dec_v_v = k / m;
	int togo = min(n, m);
	int curidx = 0, cnt = 0;
	int goal = v[dec_v].size() - dec_v_v;
	while (1) {
		pair<int, int>cur = { -1, -1 };
		for (int i = 0; i < togo; i++) {
			if (!isempty[i]) {
				if (cur.first < v[i][idx1[i]].first) {
					cur = v[i][idx1[i]];
					curidx = i;
				}
				else if (cur.first == v[i][idx1[i]].first) {
					if (cur.second < v[i][idx1[i]].second) {
						cur = v[i][idx1[i]];
						curidx = i;
					}
				}
			}
		}
		if (curidx == dec_v &&	v[curidx].size()-idx1[curidx] == goal) break; 
		idx1[curidx]++;
		cnt++;
		if (v[curidx].size()==idx1[curidx]) isempty[curidx] = 1;
	}
	cout << cnt;
}