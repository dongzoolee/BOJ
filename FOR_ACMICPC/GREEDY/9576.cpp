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
vector<pair<int, int>>v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	int n, m, a, b;
	while (tc--) {
		cin >> n >> m;
		while (m--) {
			cin >> a >> b;
			v.push_back({ a,b });
		}

	}
}