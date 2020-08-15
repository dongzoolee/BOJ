#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int arr[5][5];
int made[1000000];
vector<vector<int>>chk(5, vector<int>(5, 0));
vector<int>v;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int tenp[] = { 1,10,100,1000,10000,100000 };
void judge() {
	int tmp = 0;
	for (int i = 0; i < 6; i++)
		tmp += v[i] * tenp[6 - 1 - i];
	made[tmp] = 1;
}
void dfs(pair<int, int>cur) {
	if (v.size() == 6) { return judge(); }

	for (int i = 0; i < 4; i++) {
		if (cur.first + dy[i] < 0 || cur.first + dy[i] >= 5 || cur.second + dx[i] < 0 || cur.second + dx[i] >= 5) continue;
		//if (chk[cur.first + dy[i]][cur.second + dx[i]]) continue;
		//chk[cur.first + dy[i]][cur.second + dx[i]] = 1;
		v.push_back(arr[cur.first + dy[i]][cur.second + dx[i]]);
		dfs({ cur.first + dy[i], cur.second + dx[i] });
		v.pop_back();
		//chk[cur.first + dy[i]][cur.second + dx[i]] = 0;
	}


}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++)
		for (int f = 0; f < 5; f++)
			cin >> arr[i][f];
	vector<int>v;
	for (int cury = 0; cury < 5; cury++)
		for (int curx = 0; curx < 5; curx++) {
			v.push_back(arr[cury][curx]);
			//chk[cury][curx] = 1;
			dfs({ cury,curx });
			//chk[cury][curx] = 0;
			v.pop_back();
		}

	cout << accumulate(made, made + 1000000, 0);
}