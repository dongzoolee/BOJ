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
int arr[64][64], n;

void divcon(int k, int square, int sum_x, int sum_y) {
	bool check = 0;
	int pre[4], pre_y[4];
	pre[0] = pre[2] = sum_x, pre[1] = pre[3] = k / 4 + sum_x;
	pre_y[0] = pre_y[1] = sum_y, pre_y[2] = pre_y[3] = k / 4 + sum_y;

	if (k >= 8) {
		for (int i = sum_y; i < k / 2 + sum_y; i++) {
			for (int f = sum_x; f < k / 2 + sum_x; f++)
				if (arr[i][f] != arr[sum_y][sum_x]) {
					check = 1;
					break;
				}
			if (check) break;
		}
		if (check) {
			cout << "(";
			divcon(k / 2, 0, pre[0], pre_y[0]);
			divcon(k / 2, 1, pre[1], pre_y[1]);
			divcon(k / 2, 2, pre[2], pre_y[2]);
			divcon(k / 2, 3, pre[3], pre_y[3]);
			cout << ")";
		}
		else if (check == 0) {
			if (arr[sum_y][sum_x] == 0)
				cout << "0";
			else
				cout << "1";
		}

	}
	else if (k == 4) {
		for (int i = sum_y; i < k / 2 + sum_y; i++) {
			for (int f = sum_x; f < k / 2 + sum_x; f++)
				if (arr[i][f] != arr[sum_y][sum_x]) {
					check = 1;
					break;
				}
			if (check) break;
		}
		if (check) {
			cout << "(";
			cout << arr[sum_y][sum_x];
			cout << arr[sum_y][sum_x + 1];
			cout << arr[sum_y + 1][sum_x];
			cout << arr[sum_y + 1][sum_x + 1];
			cout << ")";
		}
		else {
			if (arr[sum_y][sum_x] == 0)
				cout << "0";
			else
				cout << "1";
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int f = 0; f < n; f++) {
			arr[i][f] = str[f] - '0';
		}
	}

	divcon(2 * n, 0, 0, 0);
}