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
using namespace std;
using ll = long long;
int n, m, k;
int add[10][10], cur[10][10];
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
//vector<tuple<int, int, int>>v;
deque<tuple<int, int, int>>dq;
deque<tuple<int, int, int>>backup;
void init() {
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++)
			cur[i][f] = 5;
}
void time() {
	//spring
	/*sort(v.begin(), v.end(), [](auto a, auto b) {
		return get<2>(a) < get<2>(b);
	});*/
	deque<tuple<int, int, int>>temp;
	while (!dq.empty()) {
		int x = get<0>(dq.front()), y = get<1>(dq.front()), z = get<2>(dq.front());
		if (cur[x][y] - z >= 0) {
			cur[x][y] -= z;
			z++;
			temp.push_back({ x,y,z });
		}
		else {
			backup.push_back(dq.front());
		}
		dq.pop_front();
	}
	temp.swap(dq);
	//summer
	while (!backup.empty()) {
		cur[get<0>(backup.front())][get<1>(backup.front())] += get<2>(backup.front()) / 2;
		backup.pop_front();
	}
	//autumn
	deque<tuple<int, int, int>>tmp;
	tmp = dq;
	while (!tmp.empty()) {
		if (get<2>(tmp.front()) % 5 == 0) {
			for (int f = 0; f < 8; f++) {
				int x = get<0>(tmp.front()) + dy[f], y = get<1>(tmp.front()) + dx[f];
				if (y < 0 || y >= n || x < 0 || x >= n) continue;
				//v.push_back({ y,x,1 });
				dq.push_front({ x,y,1 });
			}
		}
		tmp.pop_front();
	}
	//winter
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++)
			cur[i][f] += add[i][f];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y, z;
	cin >> n >> m >> k;
	init();
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++)
			cin >> add[i][f];
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		//	v.push_back({ y - 1,x - 1,z });
		dq.push_back({ x-1,y - 1,z });
	}
	/*sort(dq.begin(), dq.end(), [](auto a, auto b) {
		return get<2>(a) < get<2>(b); });*/
	for (int i = 0; i < k; i++)
		time();
	cout << dq.size();
}