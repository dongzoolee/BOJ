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
#define MAX 20001
using namespace std;
using ll = long long;
vector<pair<int, int>>v[MAX];
int n, e, st;
int dist[MAX];

void dijk(int st) {
	fill(dist, dist + MAX, 300'000);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	dist[st] = 0;
	pq.push({ 0,st });

	while (!pq.empty()) {
		int d = pq.top().first, cur = pq.top().second;
		pq.pop();

		if (dist[cur] < d) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int d = v[cur][i].first, next = v[cur][i].second;
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> e >> st;
	int a, b, c;
	while (e--) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
	}
	dijk(st);

	for (int i = 1; i <= n; i++) {
		if (dist[i] == 300'000)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}