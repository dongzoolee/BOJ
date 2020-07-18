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
#include <ctime>
using namespace std;
using ll = long long;
int n, m, strt, dest;
vector<pair<int, int>>adj[1001]; // 경로 저장
int dist[1001]; // strt → idx에 도달하는데 드는 최소비용 저장용
void dijk(int st) {
	fill(dist, dist + 1001, INT_MAX);
	// INF로 채워버림
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push({ 0,st }); // 기본적으로 출발지점 → 출발지점은 비용 0.
	dist[st] = 0;
	while (!pq.empty()) { // BFS와 유사
		int cur = pq.top().second, cost = pq.top().first;
		// while문 내에서 계속 시뮬레이션 돌릴거임.
		// cur는 현재 시뮬레이션 진행중인 출발점의 위치
		pq.pop();

		if (dist[cur] < cost) continue;

						 // adj[cur]에 도착점의 위치가 저장되어있음
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].second, cost = adj[cur][i].first;
			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int in1,in2,in3;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> in1 >> in2 >> in3;
		adj[in1].push_back({ in3,in2 });
		// 순서 바꿔야 pq가 first를 기준으로 greater배열을 진행한다.
	}
	cin >> strt >> dest;
	dijk(strt);

	cout << dist[dest];
}