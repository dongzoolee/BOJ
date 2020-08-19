#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
using ll = long long;
vector<int>v[10001];
int arr[10001][10001];
int n, m;
void floyd() {
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][h] && arr[h][j])
					arr[i][j] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int k; // 출발지점
	int a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		arr[a][b] = 1;
	}
	cin >> k;
	floyd();
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += arr[i][k];
	}
	if (arr[k][k])
		cout << n - cnt;
	else
		cout << n - cnt - 1;

}