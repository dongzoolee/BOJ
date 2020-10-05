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
vector<string>v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	string str;
	while (n--) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	while (m--) {
		cin >> str;
		if (binary_search(v.begin(), v.end(), str))
			cnt++;
	}
	cout << cnt;
}