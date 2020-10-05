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
#include<map>
using namespace std;
using ll = long long;
vector<string>mp;
vector<string>v[100];
map<string, int>mm;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	string str;
	int mem;
	for (int i = 0; i < n; i++) {
		cin >> str;
		mp.push_back(str);
		mm.insert({ str, i });
		cin >> mem;
		while (mem--) {
			cin >> str;
			v[i].push_back(str);
		}
		sort(v[i].begin(), v[i].end());
	}
	while (m--) {
		cin >> str;
		cin >> mem;
		if (mem) {
			for (int i = 0; i < n; i++) {
				if (binary_search(v[i].begin(), v[i].end(), str)) {
					cout << mp[i] << '\n';
					break;
				}
			}
		}
		else {
			int sv = mm[str];
				for (int i = 0; i < v[sv].size(); i++) {
					cout << v[sv][i]<<'\n';
			}
		}
	}
}