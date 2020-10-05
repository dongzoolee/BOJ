#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
using ll = long long;
deque<int>q;
int dp[2001][2001];
int n, m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int a, b;
	q.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push_back(a);
	}

	// 짝수개 길이일 때
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		if (q[i] == q[i - 1]) {
			dp[i - 1][i] = 1;
		}
	}

	// 홀수개 길이일 때
	for (int i = 2; i <= n - 1; i++)
		for (int j = 1; j <= n - i; j++)
			if (q[j] == q[j + i] && dp[j + 1][j + i - 1]) {
				dp[j][j + i] = 1;
			}

	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
}