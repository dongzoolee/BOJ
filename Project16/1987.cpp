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
int arr[20][20], n, m, min_ = 0;
int chk[26] = { 0 };
int mvx[4] = { 1,0,-1,0 };
int mvy[4] = { 0,-1,0,1 };
void bfs() {
	queue<pair<int, int>>q;

}
void bt(pair<int, int> cur, int cnt) {
	for (int i = 0; i < 4; i++) {
		if (0 <= cur.first + mvy[i] && cur.first + mvy[i] < n && 0 <= cur.second + mvx[i] && cur.second + mvx[i] < m)
			if (chk[arr[cur.first + mvy[i]][cur.second + mvx[i]]] == 0) {
				chk[arr[cur.first + mvy[i]][cur.second + mvx[i]]] = 1;
				bt({ cur.first + mvy[i],cur.second + mvx[i] }, cnt + 1);
				chk[arr[cur.first + mvy[i]][cur.second + mvx[i]]] = 0;
			}
			else
				min_ = max(min_, cnt);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string inp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> inp;
		for (int f = 0; f < inp.length(); f++)
			arr[i][f] = inp[f] - 'A';
	}
	chk[arr[0][0]] = 1;
	bt({ 0,0 }, 1);
	cout << min_;
}