#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
using ll = long long;
vector<pair<int, int>>adj[20001];
int dist[20001];
// Dijkstra algorithm
// 한 정점에서 다른 정점까지의 최단경로
// 한 목적지로 가는 모든 최단경로

void dijk(int st) {
	fill(dist, dist + 20001, 1000000);
	// INF로 채워버림
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 출발지, 최소거리 pair
	// 최소 거리 순으로 방문해야한다. & pair의 first를 기준으로 pq 배열이 되기 때문에
	// 거리를 first에 놓는다.
	pq.push({ 0, st });
	dist[st] = 0;
	while (!pq.empty()) {
		int curr = pq.top().second, d = pq.top().first;
		pq.pop();

		if (dist[curr] < d) continue;



		for (int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i].second, d = adj[curr][i].first;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				// 최단경로로 바꿔치기
				pq.push({ dist[next], next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int v, e, strt, inp1, inp2, inp3;
	cin >> v >> e >> strt;
	for (int i = 0; i < e; i++) {
		cin >> inp1 >> inp2 >> inp3;
		adj[inp1].push_back({ inp3, inp2 });
	}
	dijk(strt);
	for (int i = 1; i <= v; i++) {
		if (dist[i] == 1000000)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}