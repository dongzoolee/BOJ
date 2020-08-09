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
#include<numeric>
using namespace std;
using ll = long long;
int n, m;
int go[101][101];
int route[101][101];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		route[a][b] = 1;
	}
	for (int h = 1; h <= n; h++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (route[i][h] && route[h][j]) {
					route[i][j] = 1;
				}

	for (int i = 1; i <= n; i++) {
		int tmp = accumulate(route[i] + 1, route[i] + n + 1, 0);
		for (int f = 1; f <= n; f++)
			tmp += route[f][i];
		cout << n - tmp - 1 << '\n';
	}
}