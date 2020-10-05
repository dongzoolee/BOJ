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
	d[x] = ++id; // 노드마다 고유한 id
	s.push(x); // 스택에 자기 자신을 삽입
	int parent = d[x];

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (d[y] == 0) // 아직 방문 전이라면
			parent = min(parent, dfs(y));
		else if (!finished[y]) // 방문 했지만 지금 dfs 중인 경우
			parent = min(parent, d[y]);
	}

	// 부모노드가 자기 자신인 경우
	bool chk = 0;
	if (parent == d[x]) {
		vector<int>tmp;
		int sz = scc.size();
		while (1) {
			int t = s.top();
			s.pop();
			tmp.push_back(t); // scc를 한 vec에 담음
			sccNum[t] = sz;
			finished[t] = 1;
			//if (inDegree[t] == 0) chk = 1;
			if (t == x) break;
		}
		//if (chk) cnt++;
		scc.push_back(tmp);
	}
	// 자신의 부모값을 반환
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
	// 1 도미노를 직접 넘어뜨려야 한다는 건 
	// indegree가 0인 정점의 개수다.
	// 2 cycle을 이룰 경우 indegree가 0이지 않지만 
	// 누가 먼저 넘어지지 않는 이상 영원히 넘어지지 않는다.
	// :: SCC로 이루어진 그래프에서 indegree가 0인 SCC의 개수를 센다.
	int tc;
	cin >> tc;
	int a, b;
	while (tc--) {
		cin >> n >> m;
		while (m--) {
			cin >> a >> b;
			v[a].push_back(b);
			// if (a != b)
			//	inDegree[b]++; // 묶은 다음에 인디그리 cnt해야댐
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