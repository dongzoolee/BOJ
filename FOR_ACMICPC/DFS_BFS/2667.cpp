#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int arr[25][25];
int n;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
vector<int>houses;
void bfs() {
	queue<pair<int, int>>q;
	bool chk[25][25]{};
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++) {
			if (chk[i][f]) continue;
			if (arr[i][f] == 0) continue;

			chk[i][f] = 1;
			q.push({ i,f });
			int cnt = 1;
			while (!q.empty()) {
				int fry = q.front().first, frx = q.front().second;
				q.pop();
				for (int h = 0; h < 4; h++) {
					int y = fry + dy[h], x = frx + dx[h];
					if (y < 0 || y >= n || x < 0 || x >= n) continue;
					if (arr[y][x] == 0) continue;
					if (chk[y][x]) continue;

					chk[y][x] = 1;
					q.push({ y,x });
					cnt++;
				}
			}
			houses.push_back(cnt);
		}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int f = 0; f < n; f++)
			arr[i][f] = str[f] - '0';
	}
	bfs();
	cout << houses.size() << '\n';
	sort(houses.begin(), houses.end());
	for (int i = 0; i < houses.size(); i++)
		cout << houses[i] << '\n';
}