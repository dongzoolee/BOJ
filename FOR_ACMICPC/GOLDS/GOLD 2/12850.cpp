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
ll n = 8, d;
vector<vector<ll>>vec(8, vector<ll>(8, 0));
vector<vector<ll>>res(8, vector<ll>(8, 0));

vector<vector<ll>> mul(vector<vector<ll>>a, vector<vector<ll>>b) {
	vector<vector<ll>>ret(8, vector<ll>(8, 0));
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
	cin >> d;
	vec[0][1] = vec[0][2] = vec[1][2] = vec[1][3] = vec[3][2] = vec[3][4] = vec[2][4] = vec[3][5] = vec[4][5] = vec[5][6] = vec[6][7] = vec[4][7] = 1;
	vec[1][0] = vec[2][0] = vec[2][1] = vec[3][1] = vec[2][3] = vec[4][3] = vec[4][2] = vec[5][3] = vec[5][4] = vec[6][5] = vec[7][6] = vec[7][4] = 1;
	exp();
	cout << res[0][0];
}