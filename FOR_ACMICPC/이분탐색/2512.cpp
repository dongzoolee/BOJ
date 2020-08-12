#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, a, m;
	cin >> n;
	int tmp = n;
	while (tmp--) {
		cin >> a;
		v.push_back(a);
	}
	cin >> m;

	int result = 0;
	int start = 1;
	int end = *max_element(v.begin(), v.end());
	int mid = (start + end) / 2;
	while (start <= end) {
		int sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
			if (v[i] < mid)
				sum += v[i];
			else
				sum += mid;

		if (sum > m)
			end = mid - 1;
		else {// 정답은 여기 포함
			result = mid;
			start = mid + 1;
		}
	}
	cout << result;
}