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
#include <tuple>
#include<numeric>
using namespace std;
using ll = long long;
ll n, m, d;
vector<vector<ll>>vec(50, vector<ll>(50, 0));
vector<vector<ll>>res(50, vector<ll>(50, 0));

vector<vector<ll>> mul(vector<vector<ll>>a, vector<vector<ll>>b) {
	vector<vector<ll>>ret(50, vector<ll>(50, 0));
	for (ll i = 0; i < n; i++)
		for (ll f = 0; f < n; f++)
			for (ll h = 0; h < n; h++)
				ret[i][f] = (ret[i][f] + a[i][h] * b[h][f]) % 1'000'000'007;
	return ret;
}
void exp() {
	for (ll i = 0; i < n; i++)
		res[i][i] = 1;
	while (d) {
		if (d % 2) {
			res = mul(res, vec);
		}
		vec = mul(vec, vec);
		d /= 2;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b;
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		cin >> a >> b;
		vec[a - 1][b - 1] = 1;
		vec[b - 1][a - 1] = 1;
	}
	cin >> d;
	exp();
	cout << res[0][0];
}