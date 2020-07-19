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
int n, m, x, y, k, ord[1000], map[20][20];
int movex[5] = { 0, 1, -1, 0, 0 };
int movey[5] = { 0, 0, 0, -1, 1 };
vector<int>dice(6, 0);
vector<int>ddice(6, 0);

void roll() {
	int curx = x, cury = y;
	for (int i = 0; i < k; i++) {
		if (0 <= curx + movex[ord[i]] && curx + movex[ord[i]] < m && 0 <= cury + movey[ord[i]] && cury + movey[ord[i]] < n) {
			ddice = dice;
			if (ord[i] == 1) { // EAST
				cury += movey[ord[i]], curx += movex[ord[i]];
				if (map[cury][curx] != 0) {
					dice[0] = map[cury][curx];
					map[cury][curx] = 0;
				}
				else {
					dice[0] = ddice[3];
					map[cury][curx] = dice[0];
				}
				dice[3] = ddice[1];
				dice[1] = ddice[5];
				dice[5] = ddice[0];
				cout << dice[1] << "\n";
			}
			if (ord[i] == 2) { // WEST
				cury += movey[ord[i]], curx += movex[ord[i]];
				dice[5] = ddice[1];
				if (map[cury][curx] != 0) {
					dice[0] = map[cury][curx];
					map[cury][curx] = 0;
				}
				else {
					dice[0] = ddice[5];
					map[cury][curx] = dice[0];
				}
				dice[3] = ddice[0];
				dice[1] = ddice[3];
				cout << dice[1] << "\n";
			}
			if (ord[i] == 3) { // NORTH
				cury += movey[ord[i]], curx += movex[ord[i]];
				dice[4] = ddice[1];
				if (map[cury][curx] != 0) {
					dice[0] = map[cury][curx];
					map[cury][curx] = 0;
				}
				else {
					dice[0] = ddice[4];
					map[cury][curx] = dice[0];
				}
				dice[2] = ddice[0];
				dice[1] = ddice[2];
				cout << dice[1] << "\n";
			}
			if (ord[i] == 4) { // SOUTH
				cury += movey[ord[i]], curx += movex[ord[i]];
				if (map[cury][curx] != 0) {
					dice[0] = map[cury][curx];
					map[cury][curx] = 0;
				}
				else {
					dice[0] = ddice[2];
					map[cury][curx] = dice[0];
				}
				dice[4] = ddice[0];
				dice[1] = ddice[4];
				dice[2] = ddice[1];
				cout << dice[1] << "\n";
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> map[i][f];
	for (int i = 0; i < k; i++)
		cin >> ord[i];

	roll();
}