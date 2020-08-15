#include<iostream>
#include<vector>
#include<algorithm>
using ll = long long;
using namespace std;
int n, k;
int arr[10];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	// 내림차순입니다.
	reverse(arr, arr + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (k / arr[i]) {
			cnt += k / arr[i];
			k %= arr[i];
		}
	}
	cout << cnt;
}