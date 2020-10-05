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
int arr[31][31];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		arr[i][1] = 1, arr[i][i] = 1;
		for (int f = 2; f < i; f++) {
			arr[i][f] = arr[i - 1][f - 1] + arr[i - 1][f];
		}
	}
	cout << arr[n][k];
}