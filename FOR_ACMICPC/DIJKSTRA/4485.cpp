#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int arr[125][125];
int dist[125][125];
int n;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dijk() {
	for (int i = 0; i < 125; i++)
		fill(dist[i], dist[i] + 125, 200'000);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

	dist[0][0] = arr[0][0];
	q.push({ 0,0 });
	while (!q.empty()) {
		int cur_y = get<0>(q.top()), cur_x = get<1>(q.top());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = cur_y + dy[i], x = cur_x + dx[i];
			if (y < 0 || x < 0 || y >= n || x >= n) continue;
			if (dist[y][x] > dist[cur_y][cur_x] + arr[y][x]) {
				dist[y][x] = dist[cur_y][cur_x] + arr[y][x];
				q.push({ y,x });
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int z = 0;
	while (++z) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++)
			for (int f = 0; f < n; f++) {
				cin >> arr[i][f];
			}
		dijk();
		cout << "Problem " << z << ": " << dist[n - 1][n - 1] << '\n';
	}
}