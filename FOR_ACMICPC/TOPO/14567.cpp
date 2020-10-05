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
	// 1. ���� ������ 0�� ��带 ť�� �����մϴ�.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	int idx = 0;
	// 2. ������ ������ ����Ƿ��� ��Ȯ�� n���� ��带 �湮�մϴ�.
	int cnt = 0;
	while (!q.empty()) {
		int qsz = q.size();
		for (int f = 0; f < qsz; f++) {
			int frt = q.front();
			// n���� �湮�ϱ� ���� ť�� empty -> ����Ŭ �߻� == ��������x
			if (frt == w) return;

			q.pop();
			// result[idx++] = frt;
			result[frt] = cnt;
			for (int i = 0; i < v[frt].size(); i++) {
				int y = v[frt][i];
				// 3. ���Ӱ� ���������� 0�� �� ������ ť�� push
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