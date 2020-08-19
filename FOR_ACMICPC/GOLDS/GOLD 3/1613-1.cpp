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
int a, b;
int arr[501][501];
int n, k;
void floyd() {
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= n; i++) {
			for (int f = 1; f <= n; f++) {
				if (arr[i][h] && arr[h][f])
					arr[i][f] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	while (k--) {
		cin >> a >> b;
		arr[a][b] = 1;
	}
	floyd();
	int s;
	cin >> s;
	while (s--) {
		cin >> a >> b;
		if (arr[a][b]) {
			cout << -1 << '\n';
		}
		else if (arr[b][a]) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}