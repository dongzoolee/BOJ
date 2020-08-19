#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
vector<int>v[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	int k; // 출발지점
	int a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	cin >> k;
}