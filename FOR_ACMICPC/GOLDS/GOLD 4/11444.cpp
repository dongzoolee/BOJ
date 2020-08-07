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
ll n;
vector<vector<ll>>inp(2, vector<ll>(2, 0));
vector<vector<ll>>res(2, vector<ll>(2, 0));
vector<vector<ll>> mul(vector<vector<ll>>a, vector<vector<ll>>b) {
	vector<vector<ll>>res(2, vector<ll>(2, 0));
	for (int i = 0; i < a.size(); i++) {
		for (int f = 0; f < a[0].size(); f++) {
			ll tmp = 0;
			for (int h = 0; h < b.size(); h++) {
				tmp = (tmp + a[i][h] * b[h][f]) % 1000000007;
			}
			res[i][f] = tmp % 1000000007;
		}
	}
	return res;
}
void exp() {
	res[0][0] = res[1][1] = 1;
	while (n) {
		if (n % 2 == 1) {
			res = mul(res, inp);
		}
		inp = mul(inp, inp);
		n /= 2;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	inp[0][0] = 0, inp[0][1] = 1, inp[1][0] = 1, inp[1][1] = 1;
	exp();
	cout << res[1][0];
}