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
vector<int>v;
int arr[201][201];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	arr[1][1] = 1;
	for (int i = 0; i < 201; i++)
		arr[i][0] = 1;
	for (int i = 2; i <= 200; i++)
		for (int f = 1; f <= i; f++)
			arr[i][f] = min(arr[i - 1][f - 1] + arr[i - 1][f], 1000000000);

	if (k > arr[m + n][n]) { cout << -1; return 0; }
	k--;

	//암기합시다..
	for (int i = m + n - 1; i >= 0; i--) {
		if (arr[i][m] > k) {
			cout << 'a';
		}
		else {
			cout << 'z';
			k -= arr[i][m--];
		}
	}
	return 0;
}