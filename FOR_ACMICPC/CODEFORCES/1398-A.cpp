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
int arr[50000];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	int n;
	while (tc--) {
		bool done = 0;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			cin >> arr[i];
		}
		for (int i = 2; i < n; i++) {
			cin >> arr[i];
			if (arr[0] + arr[1] <= arr[i] && done == 0) {
				cout << 1 << ' ' << 2 << ' ' << i + 1 << '\n';
				done = 1;
			}
		}
		if (done == 0) cout << -1 << '\n';
	}
}
