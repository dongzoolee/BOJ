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
char arr[2200][2200];

void init() {
	for (int i = 0; i < 2200; i++)
		for (int f = 0; f < 2200; f++)
			arr[i][f] = ' ';
}

void star(int num, int y, int x) {
	if (num == 1) {
		arr[y][x] = '*';
		return;
	}
	for (int i = 0; i < 3; i++)
		for (int f = 0; f < 3; f++) {
			if (i == 1 && f == 1) continue;
			else {
				star(num / 3, y + i * (num / 3), x + f * (num / 3));
				// i배 f배 해줌으로써 8개의 사각형에 한번씩 방문하는 것
			}
		}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	star(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int f = 0; f < n; f++)
			cout << arr[i][f];
		cout << '\n';
	}
}