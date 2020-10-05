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
deque<int>q;
vector<int>list;
vector<int>v[101];
int chk[101] = { 0 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a;
	for (int i = 0; i < k; i++) {
		cin >> a;
		list.push_back(a);
		v[a].push_back(i);
	}
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (cnt < n) {
			chk[list[i]] = 1;
			q.push_back(list[i]);
			cnt++;
		}
		else {
			vector<pair<int,int>>tmp;
			for (int f = 0; f < q.size(); f++) {
				tmp.push_back({ *lower_bound(v[q[f]].begin(), v[q[f]].end(), i), q[f] });
			}
			sort(tmp.begin(), tmp.end());
			tmp[0].first tmp[1].second
		}

	}
}