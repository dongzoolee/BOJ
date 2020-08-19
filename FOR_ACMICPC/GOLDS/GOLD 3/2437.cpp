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
int arr[1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	if (arr[0] != 1) {
		cout << 1;
	}
	else {
		int end = arr[0];
		for (int i = 1; i < n; i++) {
			if (end + 1 >= arr[i]) {
				end += arr[i];
			}
			else {
				cout << end + 1;
				return 0;
			}
		}
		cout << end + 1;
	}
}