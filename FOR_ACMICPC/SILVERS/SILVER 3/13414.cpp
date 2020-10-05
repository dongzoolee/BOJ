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
#include<set>
#include <numeric>
using namespace std;
using ll = long long;
vector<string>v;
vector<string>ans;
set<string>s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	string str;
	for (int i = 0; i < m; i++) {
		cin >> str;
		v.push_back(str);
	}
	for (int i = m - 1; i >= 0; i--) {
		if (s.find(v[i]) == s.end()) {
			ans.push_back(v[i]);
			s.insert(v[i]);
		}
	}
	int ss = ans.size() - 1;
	for (int i = 0; i < n && ss - i >= 0; i++) {
		cout << ans[ss - i] << '\n';
	}
}