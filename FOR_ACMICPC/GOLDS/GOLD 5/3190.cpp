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
int map[100][100] = { 0 }, n, m, k, cnt = 0;
int movex[4] = { 1,0,-1,0 };
int movey[4] = { 0,-1,0,1 };
vector<pair<int, char>>turn;

int game() {
	map[0][0] = 2;
	queue<pair<int, int>>snake;
	pair<int, int>head = { 0,0 };
	snake.push({ 0,0 });
	pair<int, int>tail = { 0,0 };
	int dir = 0; // dir = 0 east // dir = 1 south 
	while (1) {	  // dir = 2 west // dir = 3 north
		cnt++;
		// move
		if (dir == 0) head.second++;
		if (dir == 1) head.first++;
		if (dir == 2) head.second--;
		if (dir == 3) head.first--;
		// halt condition
		if ((head.first < 0 || head.first >= n) || (head.second < 0 || head.second >= n)) return cnt;
		if (map[head.first][head.second] == 2) return cnt;
		// move2
		snake.push({head.first, head.second});

		// eat apple

		// no apple
		if (map[head.first][head.second] == 0) {
			map[tail.first][tail.second] = 0;
			snake.pop();
			tail = {snake.front().first ,snake.front().second };
		}
		// turn condition
		if (!turn.empty())
			if (turn.front().first == cnt) {
				if (turn.front().second == 'L') {
					if (dir == 0) dir = 3;
					else dir--;
				}
				else {
					if (dir == 3) dir = 0;
					else dir++;
				}
				turn.erase(turn.begin());
			}

		map[head.first][head.second] = 2;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a; char b;
		cin >> a >> b;
		turn.push_back({ a,b });
	}
	cout << game();
}