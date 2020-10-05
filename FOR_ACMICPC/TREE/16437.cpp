#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long;
vector<int>v[123457];
vector<int>sp;
int wolf[123457], sheep[123457];
int chk[123457] = { 0 };
int visited[123457] = { 0 };
ll ans = 0;
void dfs(int idx, ll sps) {
	
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	char ch;
	int a, b;
	for (int i = 2; i <= n; i++) {
		cin >> ch >> a >> b;
		v[i].push_back(b);
		v[b].push_back(i);
		if (ch == 'S') {
			sheep[i] = a;
			sp.push_back(i);
		}
		else
			wolf[i] = a;
	}
	for (int i = 0; i < sp.size(); i++) {
		
	}
	cout << ans;
}