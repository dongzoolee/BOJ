#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int n;
int par[1001], chk[1001];
struct sq {
	int a, b, c, d;
};
vector<sq>v;
int cross(int a, int b, int c, int d, int e, int f) {
	return (c - a) * (f - b) - (d - b) * (e - a);
}
int find(int a) {
	if (par[a] == a) return a;

	return par[a] = find(par[a]);
}
void unite(int a, int b) {
	a = find(a), b = find(b);

	if (a == b)return;

	if (a > b) swap(a, b);
	par[b] = a;
}
void init() {
	for (int i = 0; i < n; i++)
		par[i] = i;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	init();
	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		sq s = { a,b,c,d };
		v.push_back(s);
	}
	for (int i = 0; i < n - 1; i++)
		for (int f = i + 1; f < n; f++) {
			int tmp1 = cross(v[i].a, v[i].b, v[i].c, v[i].d, v[f].a, v[f].b);
			int tmp2 = cross(v[i].a, v[i].b, v[i].c, v[i].d, v[f].c, v[f].d);
			if (tmp1 * tmp2 <= 0) {
				if (tmp1 == 0 && tmp2 == 0) {
					if (v[i].a < v[f].a && v[i].a < v[f].b && v[i].b < v[f].a && v[i].b < v[f].b);
					else if (v[i].c < v[f].c && v[i].c < v[f].d && v[i].d < v[f].c && v[i].d < v[f].d);
					else if (v[i].a > v[f].a && v[i].a > v[f].b && v[i].b > v[f].a && v[i].b > v[f].b);
					else if (v[i].c > v[f].c && v[i].c > v[f].d && v[i].d > v[f].c && v[i].d > v[f].d);
					else
						unite(i, f);
				}
				else
					unite(i, f);
			}
		}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			cnt++;
		}
	}
	cout << cnt;
}