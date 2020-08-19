#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[501][501];
int cost[501];
int sum[501];
int tc, k, i;
//// tx에서 ty까지의 최소값을 구함
//int dpf(int tx, int ty) {
//    // 2진수로는 0x3f3f3f3f
//    // byte로는 0x3f
//    if (dp[tx][ty] != 0x3f3f3f3f)
//        return dp[tx][ty];
// 
//    if (tx == ty)
//        return dp[tx][ty] = 0;
//
//    if (tx + 1 == ty)
//        return dp[tx][ty] = cost[tx] + cost[ty];
//
//    for (int mid = tx; mid < ty; ++mid) {
//        int left = dpf(tx, mid);
//        int right = dpf(mid + 1, ty);
//        dp[tx][ty] = min(dp[tx][ty], left + right);
//    }
//
//    return dp[tx][ty] += sum[ty] - sum[tx - 1];
//}

int main() {
	// freopen("input.txt", "r", stdin);
	cin >> tc;
	while (tc--) {
		int dp[501][501]{};
		// 0x3f은 INF로 충분합니다
		cin >> k;
		for (i = 1; i <= k; ++i) {
			cin >> cost[i];
			// 1번 ~ i번까지의 합인 sum[i]
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int d = 1; d <= k; d++) {
			for (int tx = 1; tx + d <= k; tx++) {
				int ty = tx + d;
				// 필요한 것만 INF처리
				dp[tx][ty] = 0x3f3f3f3f;
				for (int mid = tx; mid < ty; mid++) {
					dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
				}
			}
		}
		// 1 ~ k의 최솟값

		cout << dp[1][k] << '\n';
	}
	return 0;
}