#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int arr[10];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, s;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> s;
	int minc, mina;
	if (n >= 2) {
		minc = *min_element(arr + 1, arr + n); // 1~n-1
		mina = min(arr[0], minc); // 0~n-1
	}
	else {
		minc = mina = arr[0];
	}
	int cur = n - 1; 
	vector<int>sum;
	int mlen = (s - minc) / mina + 1;
	// 1. s - minc가 음수가 되어서 음수 나눗셈에 의해 mlen이 음수가 될 가능성이 있다.
	if (s - minc < 0) {
		if (s >= arr[0]) {
			cout << 0;
		}
		else;
		return 0;
	}
	for (int i = n - 1; i >= 0; i--)
		if (s - arr[i] >= 0 && mlen == (s - arr[i]) / mina + 1) {
			sum.push_back(i);
			s -= arr[i];
			break;
		}
	// 2. head number를 구할 때 0이 구해져버리면... 밑에 while에서 0을 하나 더 발견할 가능성이 있다.
	if (sum[0] == 0) { cout << 0; return 0; }
	while (s >= mina) {
		if (s - arr[cur] >= 0 && s / mina - 1 == (s - arr[cur]) / mina) {
			sum.push_back(cur);
			s -= arr[cur];
		}
		else {
			cur--;
		}
	}
	for (int i = 0; i < sum.size(); i++) cout << sum[i];
}