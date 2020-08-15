#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
vector<int>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int sum = v[0];
	int sub[1000] = { 0 };
	sub[0] = v[0];
	for (int i = 1; i < n; i++) {
		sub[i] = sub[i - 1]+v[i];
		sum += sub[i];
	}
	cout << sum;
}