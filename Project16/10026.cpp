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
int n;
char nor[100][100], abn[100][100];
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };

void nor_judge() {
	int cnt = 0;
	queue<pair<int, int>> q;
	bool chk[100][100] = { 0 };

	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++) {
			if (chk[i][f] == 1) continue;
			chk[i][f] = 1;
			q.push({ i, f });

			while (!q.empty()) {
				int qf = q.front().first, qs = q.front().second;
				q.pop();
				for (int h = 0; h < 4; h++) {
					if (0 <= qf + y[h] && qf + y[h] < n && 0 <= qs + x[h] && qs + x[h] < n) {
						if (nor[qf + y[h]][qs + x[h]] == nor[qf][qs] && chk[qf + y[h]][qs + x[h]] == 0) {
							chk[qf + y[h]][qs + x[h]] = 1;
							q.push({ qf + y[h], qs + x[h] });
						}
					}
				}
			}
			cnt++;
		}
	cout << cnt << " ";
}

void abn_judge() {
	int cnt = 0;
	queue<pair<int, int>> q;
	bool chk[100][100] = { 0 };

	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++) {
			if (chk[i][f] == 1) continue;
			chk[i][f] = 1;
			q.push({ i, f });

			while (!q.empty()) {
				int qf = q.front().first, qs = q.front().second;
				q.pop();
				for (int h = 0; h < 4; h++) {
					if (0 <= qf + y[h] && qf + y[h] < n && 0 <= qs + x[h] && qs + x[h] < n) {
						if (abn[qf + y[h]][qs + x[h]] == abn[qf][qs] && chk[qf + y[h]][qs + x[h]] == 0) {
							chk[qf + y[h]][qs + x[h]] = 1;
							q.push({ qf + y[h], qs + x[h] });
						}
					}
				}
			}
			cnt++;
		}
	cout << cnt;
}
	int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++) {
			cin >> nor[i][f];
			if (nor[i][f] == 'G')
				abn[i][f] = 'R';
			else
				abn[i][f] = nor[i][f];
		}
	nor_judge();
	abn_judge();
}