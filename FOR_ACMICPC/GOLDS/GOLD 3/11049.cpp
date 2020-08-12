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
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int st, cur, cnt;
int n, a, b;
int chk[1000002] = { 0 };
void bfs() {
	queue<int>q;
	chk[cur] = 1;
	q.push(cur);
	while (!q.empty()) {
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			if (q.front() == st)
				return;
			if (q.front() - st >= a && chk[q.front() - a] == 0) { chk[q.front() - a] = 1; q.push(q.front() - a); }
			if (q.front() - st >= b && chk[q.front() - b] == 0) { chk[q.front() - b] = 1;  q.push(q.front() - b); }
			if (q.front() - st >= 1 && chk[q.front() - 1] == 0) { chk[q.front() - 1] = 1;  q.push(q.front() - 1); }
			q.pop();
		}
		st++;
		cnt++;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b;
	st = 1, cur = n + 1, cnt = 0;
	// a가 b보다 큽니다
	bfs();
	cout << cnt;
}