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
vector<int>v(1, -1000000001);
vector<int>ans(1, -1000000001);
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (v.back() < cur) {
			ans.push_back(cur);
			v.push_back(cur);
		}
		else {
			if (lower_bound(v.begin(), v.end(), cur) - v.begin() == v.size() - 1) {
				ans[ans.size() - 1] = cur;
				v[v.size() - 1] = cur;
			}
			else 
				*lower_bound(v.begin(), v.end(), cur) = cur;
		}
	}
	cout << ans.size() - 1 << '\n';
	for (int i = 1; i < ans.size(); i++)
		cout << ans[i] << ' ';
}