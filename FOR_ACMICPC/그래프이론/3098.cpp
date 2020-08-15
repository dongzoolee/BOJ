#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int chk[51][51];
int cnt[51];
vector<int>v[51];
vector<int>tmp[51];
int n, m;
vector<int>days;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		chk[a][b] = 1;
		chk[b][a] = 1;
		cnt[a]++;
		cnt[b]++;
	}
	bool connected = 1;
	while (connected) {
		connected = 0;
		int count = 0;
		for (int i = 1; i <= n; i++) {
			chk[i][i] = 1;
			// i의 친구 호출
			for (int f = 0; f < v[i].size(); f++) {
				// i의 친구인 f의 친구(==h) 호출
				for (int h = 0; h < v[v[i][f]].size(); h++) {
					if (chk[v[v[i][f]][h]][i] && chk[i][v[v[i][f]][h]]) continue;
					// h랑 i는 이제 친구
					connected = 1;
					tmp[v[v[i][f]][h]].push_back(i);
					tmp[i].push_back(v[v[i][f]][h]);
					chk[v[v[i][f]][h]][i] = 1;
					chk[i][v[v[i][f]][h]] = 1;
					count++;
				}
			}
		}
		days.push_back(count);
		for (int i = 1; i <= n; i++) {
			v[i].insert(v[i].end(), tmp[i].begin(), tmp[i].end());
			tmp[i].clear();
		}
	}
	cout << days.size() - 1 << '\n';
	for (int i = 0; i < days.size() - 1; i++) {
		cout << days[i] << '\n';
	}
}