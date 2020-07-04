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
int f, s, g, u, d, counter = 0, depth = 0;
bool checker[1000001] = { 0 };
// BFS 키워드 제시

int bfs() {
	queue<int> q;
	q.push(s);
	checker[s] = 1;

	while (!q.empty()) {
		int q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			int frt = q.front();
			q.pop();

			if (frt + u <= f) {
				if (checker[frt + u] == 0) {
					q.push(frt + u);
					checker[frt + u] = 1;
				}
			}		
			if (frt - d > 0) {
				if (checker[frt - d] == 0) {
					q.push(frt - d);
					checker[frt - d] = 1;
				}
			}
			if (frt == g)
				return 1; // 완성
		}
		depth++;
	}
	return 0; // 미완성
}
int main() {
	cin >> f >> s >> g >> u >> d;

	if (s > g) {
		if (d == 0) {
			cout << "use the stairs";
			return 0;
		}
		else if ((s - g) % d == 0) {
			counter = (s - g) / d;
		}
		else if (u == 0) { // (s - g) % d != 0
			cout << "use the stairs";
			return 0;
		}
		else if (s+u>f && s-d < 1) {
			cout << "use the stairs";
			return 0;
		}
		else {
			if(bfs())
				counter = depth;
			else {
				cout << "use the stairs";
				return 0;
			}
		}
	}
	else if (s < g) {
		if (u == 0) {
			cout << "use the stairs";
			return 0;
		}
		else 	if ((g - s) % u == 0) {
			counter = (g - s) / u;
		}
		else if (d == 0) { // (g - s) % u != 0
			cout << "use the stairs";
			return 0;
		}
		else if (s + u > f && s - d < 1) {
			cout << "use the stairs";
			return 0;
		}
		else {
			if (bfs())
				counter = depth;
			else {
				cout << "use the stairs";
				return 0;
			}
		}
	}
	else { // s == g
	}
	cout << counter;
}