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
int n, a;
ll res = 1;
int comb[23][23];
void reg(vector<int>vec) {
	if (vec.size() <= 1) return;
	vector<int>left;
	vector<int>right;
	// 0번은 항상 root
	int fst = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		if (fst < vec[i])
			right.push_back(vec[i]);
		else
			left.push_back(vec[i]);
	}
	res = (comb[vec.size() - 1][left.size()] % 9'999'991) * (res % 9'999'991) % 9'999'991;
	reg(left);
	reg(right);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	comb[1][1] = 1;
	for (int i = 0; i < 23; i++) comb[i][0] = 1;
	for (int i = 2; i < 23; i++)
		for (int f = 1; f < 23; f++)
			comb[i][f] = (comb[i - 1][f] + comb[i - 1][f - 1]) % 9'999'991;
	int tc;
	cin >> tc;
	while (tc--) {
		vector<int>v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		reg(v);
		v.clear();
		cout << res << '\n';
		res = 1;
	}
}