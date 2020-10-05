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
vector<pair<string, int>>pkm;
vector<string>og;
int tenp[] = { 1,10,100,1000,10000,100000, 1000000 };
int mknum(string str) {
	int slen = str.length(), ret = 0;
	for (int i = 0; i < slen; i++) {
		ret += (str[i] - '0') * tenp[slen - i - 1];
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	string str;
	og.push_back("aaa");
	for (int i = 1; i <= n; i++) {
		cin >> str;
		pkm.push_back({ str, i });
		og.push_back(str);
	}
	sort(pkm.begin(), pkm.end());
	while (m--) {
		cin >> str;
		if ('0' <= str[0] && str[0] <= '9') {
			cout << og[mknum(str)] << '\n';
		}
		else {
			cout << pkm[lower_bound(pkm.begin(), pkm.end(), make_pair(str,0)) - pkm.begin()].second << '\n';
		}
	}
}