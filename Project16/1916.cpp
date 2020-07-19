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
vector<pair<int, int>>adj[1001]; // ��� ����
int dist[1001]; // strt �� idx�� �����ϴµ� ��� �ּҺ�� �����
void dijk(int st) {
	fill(dist, dist + 1001, INT_MAX);
	// INF�� ä������
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push({ 0,st }); // �⺻������ ������� �� ��������� ��� 0.
	dist[st] = 0;
	while (!pq.empty()) { // BFS�� ����
		int cur = pq.top().second, cost = pq.top().first;
		// while�� ������ ��� �ùķ��̼� ��������.
		// cur�� ���� �ùķ��̼� �������� ������� ��ġ
		pq.pop();

		if (dist[cur] < cost) continue;

						 // adj[cur]�� �������� ��ġ�� ����Ǿ�����
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
		// ���� �ٲ�� pq�� first�� �������� greater�迭�� �����Ѵ�.
	}
	cin >> strt >> dest;
	dijk(strt);

	cout << dist[dest];
}