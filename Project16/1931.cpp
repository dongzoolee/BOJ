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
#include <ctime>
using namespace std;
using ll = long long;
vector<pair<int, int>>v;
// 그리디 알고리즘의 보장
// ㅇㅋ ㅋㅋ
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), [](auto a, auto b) {
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
	});

	int i, cnt = 1, cur = v[0].second;
		for (i = 1; i < n; i++) {
			if (cur <= v[i].first) {
				cnt++;
				cur = v[i].second;
				continue;
			}
		}
	cout << cnt;
}