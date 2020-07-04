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
using namespace std;
using longs = long long;
int arr[1000][1000];
bool checker[1000][1000] = { 0 };
vector <pair<int, int>> save;
queue<pair<int, int>> q;
int m, n, counter = 0;

void bfs() {
	// 주의합시다 !!!!!! 큐에 넣는 즉시 방문처리 안해주면 메모리 초과날 수 있음
	while (!q.empty()) {
		int x = q.size();
		for (int i = 0; i < x; i++) {
			int xx = q.front().first, yy = q.front().second;

			if (0 <= yy + 1 && yy + 1 < m && checker[xx][yy + 1] == 0 && arr[xx][yy + 1] == 0) {
				q.push({ xx, yy + 1 });
				checker[xx][yy + 1] = 1;
			}
			if (0 <= yy - 1 && yy - 1 < m && checker[xx][yy - 1] == 0 && arr[xx][yy - 1] == 0) {
				q.push({ xx, yy - 1 });
				checker[xx][yy - 1] = 1;
			}
			if (0 <= xx + 1 && xx + 1 < n && checker[xx + 1][yy] == 0 && arr[xx + 1][yy] == 0) {
				q.push({ xx + 1, yy });
				checker[xx + 1][yy] = 1;
			}
			if (0 <= xx - 1 && xx - 1 < n && checker[xx - 1][yy] == 0 && arr[xx - 1][yy] == 0) {
				q.push({ xx - 1, yy });
				checker[xx - 1][yy] = 1;
			}
			q.pop();
		}
		counter++;
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			cin >> arr[i][f];
			if (arr[i][f] == 1) {
				q.push({ i,f });
				checker[i][f] = 1;
			}
		}
	bfs();

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			if (checker[i][f] != 1)
				if (arr[i][f]  == 0) {
					cout << "-1";
					return 0;
				}
		}
	cout << counter-1;
}