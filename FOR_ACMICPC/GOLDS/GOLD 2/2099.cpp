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
int n, k, m;
vector<vector<int>> arr(200, vector<int>(200, 0));
vector<vector<int>> forpow(200, vector<int>(200, 0));

vector<vector<int>> mul(vector<vector<int>>a, vector<vector<int>>b) {
	vector<vector<int>> ret(200, vector<int>(200, 0));
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++) {
			for (int h = 0; h < n; h++)
				ret[i][f] += a[i][h] * b[h][f];
		}
	return ret;
}
void exp() {
	for (int i = 0; i < n; i++)
		forpow[i][i] = 1;

	while (k) {
		if (k % 2) {
			forpow = mul(forpow, arr);
		}
		arr = mul(arr, arr);
		k /= 2;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[i][a - 1] = 1;
		arr[i][b - 1] = 1;
	}
	exp();
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (forpow[a - 1][b - 1] != 0)
			cout << "death\n";
		else
			cout << "life\n";
	}
}