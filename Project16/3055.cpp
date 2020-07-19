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
int arr[50][50], r, c, cnt = 0;
vector<pair<int, int>>loc[3];
int movex[4] = { 1,0,-1,0 };
int movey[4] = { 0,-1,0,1 };
int bfs() {
	// ���̷��� ��
	queue<pair<int, int>>q;
	for (int i = 0; i < loc[2].size(); i++)
		q.push(loc[2][i]);

	//����ġ ��
	queue<pair<int, int>>qq;
	bool chk[50][50] = { 0 };
	qq.push(loc[0][0]);

	while (!qq.empty()) { // ��
		int qqsz = qq.size();
		for (int i = 0; i < qqsz; i++) {
			int fr1 = qq.front().second, fr2 = qq.front().first;
			qq.pop();
			for (int f = 0; f < 4; f++) { // ����ġ moving
				int x = fr1 + movex[f], y = fr2 + movey[f];
				if (0 <= x && x < c && 0 <= y && y < r) {
					if (arr[y][x] == 0 && chk[y][x] == 0) {
						chk[y][x] = 1;
						qq.push({ y,x });
					}
					if (loc[1].front().second == x && loc[1].front().first == y)
						if (arr[y - movey[f]][x - movex[f]] == 0)
							return cnt;
				}
			}
		} // end of ����ġ qqsz

		if (!q.empty()) {
			int qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				int fr1 = q.front().second, fr2 = q.front().first;
				q.pop();
				for (int f = 0; f < 4; f++) { // virus moving
					int xx = fr1 + movex[f], yy = fr2 + movey[f];
					if (0 <= xx && xx < c && 0 <= yy && yy < r) {
						if (arr[yy][xx] == 0) {
							arr[yy][xx] = 1;
							q.push({ yy,xx });
						}
					}
				} // end of movex, y
			}
		}// end of qsz
		cnt++;
	}// end of while
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int f = 0; f < c; f++) {
			char inp;
			cin >> inp;
			if (inp == '.') {
				arr[i][f] = 0; // �� �� �ִ� ��
			}
			if (inp == 'D') {
				arr[i][f] = 2; // �� �� ���� ��
				loc[1].push_back({ i, f });
			}
			if (inp == 'S') {
				arr[i][f] = 0; // �� �� �ִ� ��
				loc[0].push_back({ i, f });
			}
			if (inp == 'X') {
				arr[i][f] = 2; // �� �� ���� rht
			}
			if (inp == '*') {
				arr[i][f] = 1; // �̹� (virus)������ ��
				loc[2].push_back({ i, f });  // �������� ����
			}
		}
	if (bfs() == -1)
		cout << "KAKTUS";
	else
		cout << cnt + 1;
}