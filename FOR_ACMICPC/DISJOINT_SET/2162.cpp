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
int par[3000];
int find(int a) {
	if (a == par[a]) return a;

	return par[a] = find(par[a]);
}
void unite(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;

	if (a > b)swap(a, b);
	par[b] = a;
}
struct line {
	double x1;
	double y1;
	double x2;
	double y2;
};
vector<line>v;
double cross(double a, double b, double c, double d, double e, double f) {
	return (c - a) * (f - b) - (d - b) * (e - a);
}
void init() {
	for (int i = 0; i < 3000; i++)
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
		line l = { a, b, c, d };
		v.push_back(l);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int f = i + 1; f < n; f++) {
			double ret1 = cross(v[i].x1, v[i].y1, v[i].x2, v[i].y2, v[f].x1, v[f].y1) *
				cross(v[i].x1, v[i].y1, v[i].x2, v[i].y2, v[f].x2, v[f].y2);
			double ret2 = cross(v[f].x2, v[f].y2, v[f].x1, v[f].y1, v[i].x1, v[i].y1) *
				cross(v[f].x2, v[f].y2, v[f].x1, v[f].y1, v[i].x2, v[i].y2);
			if (ret1 <= 0 && ret2 <= 0) {
				if (ret1 == 0 && ret2 == 0) {
					if (v[i].x1 < v[f].x1 && v[i].x1 < v[f].x2 && v[i].x2 < v[f].x1 && v[i].x2 < v[f].x2);
					else if (v[i].y1 < v[f].y1 && v[i].y1 < v[f].y2 && v[i].y2 < v[f].y1 && v[i].y2 < v[f].y2);
					else if (v[i].x1 > v[f].x1 && v[i].x1 > v[f].x2 && v[i].x2 > v[f].x1 && v[i].x2 > v[f].x2);
					else if (v[i].y1 > v[f].y1 && v[i].y1 > v[f].y2 && v[i].y2 > v[f].y1 && v[i].y2 > v[f].y2);
					else
						unite(i, f);
				}
				else
					unite(i, f);
			}
		}
	}
	int chk[3000]{};
	int cnt = 0,res=0;
	for (int i = 0; i < n; i++) {
		int tmp = find(i);
		if (!chk[tmp]) cnt++;
		chk[tmp]++;
		res = max(res, chk[tmp]);
	}
	cout << cnt << '\n' << res;
}