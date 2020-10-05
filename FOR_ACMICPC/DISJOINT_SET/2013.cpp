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
int par[10000], chk[10000];
double cross(double a, double b, double c, double d, double e, double f) {
	return (c - a) * (f - b) - (d - b) * (e - a);
}
struct line {
	double a, b, c, d;
};
vector<line>v;
int find(int a) {
	if (a == par[a]) return par[a];

	return par[a] = find(par[a]);
}
void unite(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;

	if (a > b)swap(a, b);
	par[b] = a;
}
void init() {
	for (int i = 0; i < 10000; i++)
		par[i] = i;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	init();
	double a, b, c, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		line l = { a,b,c,d };
		v.push_back(l);
	}

	for (int i = 0; i < n - 1; i++)
		for (int f = i + 1; f < n; f++) {
			double tmp1 = cross(v[i].a, v[i].b, v[i].c, v[i].d, v[f].a, v[f].b);
			double tmp2 = cross(v[i].a, v[i].b, v[i].c, v[i].d, v[f].c, v[f].d);
			if (tmp1 == 0 && tmp1 != 0) {
				if (v[i].a == v[f].a && v[i].b == v[f].b)
					unite(i, f);
				else if (v[i].c == v[f].a && v[i].d == v[f].b)
					unite(i, f);
			}
			else if (tmp1 != 0 && tmp2 == 0) {
				if (v[i].a == v[f].c && v[i].b == v[f].d)
					unite(i, f);
				else if (v[i].c == v[f].c && v[i].d == v[f].d)
					unite(i, f);
			}
			else if (tmp1 == 0 && tmp2 == 0) {
				if (v[i].a <= v[f].a && v[f].a <= v[i].c) {
					if (v[i].b <= v[f].b && v[f].b <= v[i].d)
						unite(i, f);
					else if (v[i].b >= v[f].b && v[f].b >= v[i].d)
						unite(i, f);
				}
				else if (v[i].a >= v[f].a && v[f].a >= v[i].c) {
					if (v[i].b <= v[f].b && v[f].b <= v[i].d)
						unite(i, f);
					else if (v[i].b >= v[f].b && v[f].b >= v[i].d)
						unite(i, f);
				}
				else if (v[i].a <= v[f].c && v[f].c <= v[i].c) {
					if (v[i].b <= v[f].d && v[f].d <= v[i].d)
						unite(i, f);
					else if (v[i].b >= v[f].d && v[f].d >= v[i].d)
						unite(i, f);
				}
				else if (v[i].a >= v[f].c && v[f].c >= v[i].c) {
					if (v[i].b <= v[f].d && v[f].d <= v[i].d)
						unite(i, f);
					else if (v[i].b >= v[f].d && v[f].d >= v[i].d)
						unite(i, f);
				}
			}
		}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int tmp = find(i);
		if (!chk[tmp]) {
			chk[tmp] = 1;
			cnt++;
		}
	}
	cout << cnt;
}