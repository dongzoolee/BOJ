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
vector<int>v[10];
vector<int>ans;
int chk[500001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	int tomake = n - k;
	for (int i = 0; i < n; i++) {
		v[str[i] - '0'].push_back(i);
	}
	sort(v->begin(), v->end());
	int head = -1;
	for (int i = 9; i >= 0; i--) {
		for (int f = 0; f < v[i].size(); f++) {
			// idx==앞에 지워야하는 수의 갯수
			if (v[i][f] - head - 1 >= 0 && v[i][f] - head - 1 <= k && n - v[i][f] >= tomake - ans.size()) {
				k -= v[i][f] - head - 1;
				ans.push_back(i);
				head = v[i][f];
			}
			if (head != -1) break;
		}
		if (head != -1) break;
	}
	cout << str[head];
	for (int i = head + 1; i < n; i++) {
		if (i - head - 1 >= 0 && i - head - 1 <= k && n - i >= tomake - ans.size()) {

		}
	}
}
