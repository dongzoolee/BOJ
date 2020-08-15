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
int arr[100000];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int frt = 0, bk = 0, sum = arr[0], curmax = INT_MAX;
	while (bk < n - 1) {
		if (sum >= s) {
			curmax = min(curmax, bk - frt + 1);
			sum -= arr[frt++];
		}
		else if (sum < s) {
			sum += arr[++bk];
		}
	}
	while (frt <= bk) {
		if (sum >= s) {
			curmax = min(curmax, bk - frt + 1);
			sum -= arr[frt++];
		}
		else if (sum < s) break;
	}
	if (curmax == INT_MAX)
		cout << "0";
	else
		cout << curmax;
}