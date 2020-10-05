#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
#define MAX 100001
int id;
int d[MAX];
bool finished[MAX] = { 0 };
vector<int> v[MAX];
vector<vector<int>>scc;
stack<int>s;
int n, m, cnt;
int inDegree[MAX];
int sccNum[MAX];
int dfs(int x) {
	d[x] = ++id; // ��帶�� ������ id
	s.push(x); // ���ÿ� �ڱ� �ڽ��� ����
	int parent = d[x];

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (d[y] == 0) // ���� �湮 ���̶��
			parent = min(parent, dfs(y));
		else if (!finished[y]) // �湮 ������ ���� dfs ���� ���
			parent = min(parent, d[y]);
	}

	// �θ��尡 �ڱ� �ڽ��� ���
	bool chk = 0;
	if (parent == d[x]) {
		vector<int>tmp;
		int sz = scc.size();
		while (1) {
			int t = s.top();
			s.pop();
			tmp.push_back(t); // scc�� �� vec�� ����
			sccNum[t] = sz;
			finished[t] = 1;
			//if (inDegree[t] == 0) chk = 1;
			if (t == x) break;
		}
		//if (chk) cnt++;
		scc.push_back(tmp);
	}
	// �ڽ��� �θ��� ��ȯ
	return parent;
}
void init() {
	cnt = 0;
	id = 0;
	memset(d, 0, sizeof(d));
	memset(finished, 0, sizeof(finished));
	memset(inDegree, 0, sizeof(inDegree));
	memset(sccNum, 0, sizeof(sccNum));
	scc.clear();
	for (int i = 0; i < 100001; i++) v[i].clear();
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	// 1 ���̳븦 ���� �Ѿ�߷��� �Ѵٴ� �� 
	// indegree�� 0�� ������ ������.
	// 2 cycle�� �̷� ��� indegree�� 0���� ������ 
	// ���� ���� �Ѿ����� �ʴ� �̻� ������ �Ѿ����� �ʴ´�.
	// :: SCC�� �̷���� �׷������� indegree�� 0�� SCC�� ������ ����.
	int tc;
	cin >> tc;
	int a, b;
	while (tc--) {
		cin >> n >> m;
		while (m--) {
			cin >> a >> b;
			v[a].push_back(b);
			// if (a != b)
			//	inDegree[b]++; // ���� ������ �ε�׸� cnt�ؾߴ�
		}
		for (int i = 1; i <= n; i++)
			if (!d[i]) dfs(i);

		for (int i = 1; i <= n; i++)
			for (int f = 0; f < v[i].size(); f++)
				if (sccNum[i] != sccNum[v[i][f]])
					inDegree[sccNum[v[i][f]]]++;

		for (int i = 0; i < scc.size(); i++)
			if (inDegree[i] == 0)
				cnt++;
		cout << cnt << '\n';
		init();
	}
}