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
int arr[102][77], n, m, cnt = 0;
bool checker[102][77] = { 0 };

void bfs() {

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {

			if (checker[i][f]) continue;

			queue<pair<int, int>>q;
			q.push({ i,f });
			checker[i][f] = 1;
			bool bong = 0;
			int og = arr[i][f];

			while (!q.empty()) {
				int x = q.front().second, y = q.front().first, xy = arr[y][x];
				q.pop();
				if (x + 1 < m) {
					if (y + 1 < n) {
						if (arr[y + 1][x + 1] <= xy && checker[y + 1][x + 1] == 0) {
							checker[y + 1][x + 1] = 1;
							q.push({ y + 1, x + 1 });
						}
						else if (arr[y + 1][x + 1] <= xy) {}
						else if (arr[y + 1][x + 1] > og) { // 스타트지점보다 크다면
							bong = 1;
						}
					}
					if (y - 1 >= 0) {
						if (arr[y - 1][x + 1] <= xy && checker[y - 1][x + 1] == 0) {
							checker[y - 1][x + 1] = 1;
							q.push({ y - 1, x + 1 });
						}
						else if (arr[y - 1][x + 1] <= xy) {}
						else if (arr[y - 1][x + 1] > og) {
							bong = 1;
						}
					}
					if (arr[y][x + 1] <= xy && checker[y][x + 1] == 0) {
						checker[y][x + 1] = 1;
						q.push({ y, x + 1 });
					}
					else if (arr[y][x + 1] <= xy) {}
					else if (arr[y][x + 1] > og) {
						bong = 1;
					}
				}

				if (x - 1 >= 0) {
					if (y + 1 < n) {
						if (arr[y + 1][x - 1] <= xy && checker[y + 1][x - 1] == 0) {
							checker[y + 1][x - 1] = 1;
							q.push({ y + 1, x - 1 });
						}
						else if (arr[y + 1][x - 1] <= xy) {}
						else if (arr[y + 1][x - 1] > og) {
							bong = 1;
						}
					}
					if (y - 1 >= 0) {
						if (arr[y - 1][x - 1] <= xy && checker[y - 1][x - 1] == 0) {
							checker[y - 1][x - 1] = 1;
							q.push({ y - 1, x - 1 });
						}
						else if (arr[y - 1][x - 1] <= xy) {}
						else if (arr[y - 1][x - 1] > og) {
							bong = 1;
						}
					}
					if (arr[y][x - 1] <= xy && checker[y][x - 1] == 0) {
						checker[y][x - 1] = 1;
						q.push({ y, x - 1 });
					}
					else if (arr[y][x - 1] <= xy) {}
					else if (arr[y][x - 1] > og) {
						bong = 1;
					}
				}
				if (y + 1 < n) {
					if (arr[y + 1][x] <= xy && checker[y + 1][x] == 0) {
						checker[y + 1][x] = 1;
						q.push({ y + 1, x });
					}
					else if (arr[y + 1][x] <= xy) {}
					else if (arr[y + 1][x] > og) {
						bong = 1;
					}
				}
				if (y - 1 >= 0) {
					if (arr[y - 1][x] <= xy && checker[y - 1][x] == 0) {
						checker[y - 1][x] = 1;
						q.push({ y - 1, x });
					}
					else if (arr[y - 1][x] <= xy) {}
					else if (arr[y - 1][x] > og) {
						bong = 1;
					}
				}

			} // end of while
			if (bong == 0)
				cnt++;
		}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];

	bfs();
	cout << cnt;
}