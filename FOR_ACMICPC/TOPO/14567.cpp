#include<iostream>
#include<queue>
using namespace std;
#define M 1001
vector<int>inDegree(M, 0);
int n, k, w;
vector<int>v[M];
int result[M];
vector<int>cost;
void topologySort() {
	queue<int>q;
	// 1. 진입 차수가 0인 노드를 큐에 삽입합니다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	int idx = 0;
	// 2. 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문합니다.
	int cnt = 0;
	while (!q.empty()) {
		int qsz = q.size();
		for (int f = 0; f < qsz; f++) {
			int frt = q.front();
			// n개를 방문하기 전에 큐가 empty -> 사이클 발생 == 위상정렬x
			if (frt == w) return;

			q.pop();
			// result[idx++] = frt;
			result[frt] = cnt;
			for (int i = 0; i < v[frt].size(); i++) {
				int y = v[frt][i];
				// 3. 새롭게 진입차수가 0이 된 정점을 큐에 push
				if (--inDegree[y] == 0)
					q.push(y);
			}
		}
		cnt++;
	}
	// end
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int m;
	cin >> n >> m;
	int a, b;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b]++;
	}
	topologySort();
	for (int i = 1; i <= n; i++)
		cout << result[i] + 1 << ' ';
}