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
int arr[32][32];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n = 31, k = 31;
	for (int i = 1; i <= n; i++) {
		arr[i][1] = 1, arr[i][i] = 1;
		for (int f = 2; f < i; f++) {
			arr[i][f] = arr[i - 1][f - 1] + arr[i - 1][f];
		}
	}
	int tc, a, b;
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		cout << arr[b + 1][a + 1] << '\n';
	}
}