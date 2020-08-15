#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int arr[30000];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	int max_ = 0;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n - 1; i++) {
		int sum = 0;
		for (int f = i + 1; f < n; f++) {
			if (arr[i] > arr[f])
				sum++;
			else break;
		}
		max_ = max(sum, max_);
	}
	cout << max_;
}