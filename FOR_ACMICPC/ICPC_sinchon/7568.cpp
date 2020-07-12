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
vector<pair<pair<int, int>,int>>v;
int n, a, b;
void judge() {
	for (int i = 0; i < n; i++) {
		bool chk[50] = { 0 };
		for (int f = 0; f < n; f++) {
			if (v[i].first.first < v[f].first.first)
				chk[f] = 1;
		}
		for (int f = 0; f < n; f++) {
			if (chk[f] == 1) {
				if (v[i].first.second < v[f].first.second)
					v[i].second++;
			}
		}
		cout <<v[i].second<< " ";
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ {a,b},1 });
	}
	judge();
}