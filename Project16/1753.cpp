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
// �� �������� �ٸ� ���������� �ִܰ��
// �� �������� ���� ��� �ִܰ��

void dijk(int st) {
	fill(dist, dist + 20001, 1000000);
	// INF�� ä������
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// �����, �ּҰŸ� pair
	// �ּ� �Ÿ� ������ �湮�ؾ��Ѵ�. & pair�� first�� �������� pq �迭�� �Ǳ� ������
	// �Ÿ��� first�� ���´�.
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
				// �ִܰ�η� �ٲ�ġ��
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