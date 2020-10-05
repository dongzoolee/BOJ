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
vector<pair<string, int>>v;
vector<string>og;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	while (!cin.eof()) {
		getline(cin, str);
		if (str == "")break;
		v.push_back({ str,0 });
		og.push_back(str);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int ogsz = og.size();
	for (int i = 0; i < ogsz; i++) {
		v[lower_bound(v.begin(), v.end(), make_pair(og[i], 0)) - v.begin()].second++;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
		cout << fixed;
		cout.precision(4);
		cout << (float)v[i].second / ogsz * 100 << '\n';
	}
}