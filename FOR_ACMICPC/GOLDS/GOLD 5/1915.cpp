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
using ll = long long;
int arr[1000][1000] = { 0 }, n, m;
bool chk[1000][1000] = { 0 };

void bfs() {
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	chk[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			if (chk[i][f] == 0 && arr[i][f] == 1) {
				int len = 0;
				while (!q.empty()) {
					for (int h = f + 1; h < m; h++) {
						chk[i][h] = 1;
						if (arr[i][h] != 1) {
							len = h - f;
							break;
						}
					}

				}
			}
		}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];
	bfs();
}