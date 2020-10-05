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
int goal[100001];
int dist[100001];
int dist2[100001];
vector<tuple<int,int, int>>v[100001];
int n, m, d, e;
void dijk2(int st) {
	fill(dist2, dist2 + 100000, -1'000'000);
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>>q;

	dist2[st] = 1; // dist2에는 만족감 - 거리*2
	q.push({ dist2[st], st, goal[st] });

	while (!q.empty()) {
		int d = get<0>(q.top()), cur = get<1>(q.top()), h=get<2>(q.top());
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int d = get<0>(v[cur][i]), next = get<1>(v[cur][i]), h = get<2>(v[cur][i]);
			if (dist2[next] < dist2[cur] + d && goal[next] > goal[cur]) {
				dist2[next] = dist2[cur] + d;
				q.push({ dist2[next],next, goal[next] });
			}
		}
	}
}
void dijk(int st) {
	fill(dist, dist + 100000, -1'000'000);
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>>q;

	dist[st] = 1; // dist에는 만족감 - 거리*2
	q.push({ dist[st], st, goal[st] });

	while (!q.empty()) {
		int d = get<0>(q.top()), cur = get<1>(q.top()), h = get<2>(q.top());
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int d = get
			(v[cur][i]), next = get<1>(v[cur][i]), h = get<2>(v[cur][i]);
			if (dist[next] < dist[cur] + d && goal[next] > goal[cur]) {
				dist[next] = dist[cur] + d;
				q.push({ dist[next],next, goal[next] });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> d >> e;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		goal[i] = a;
	}
	while (m--) {
		cin >> a >> b >> c;
		if (a > b)swap(a, b);
		v[a].push_back({ goal[b] - c, b, goal[b] });
		v[b].push_back({ goal[b] - c, a, goal[a] });
	}
	dijk(1);
	dijk2(n);
	if (dist[n] == 1'000'000)
		cout << "Impossible";
	else
		cout << dist[n] + 2;
}