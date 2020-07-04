#include <iostream>
#include <stdio.h>
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
int arr[2781][2781], ct__1 = 0, ct_0 = 0, ct_1 = 0;
void segment(int num, int x_index, int y_index);

void judge(int num, int x_index, int y_index) {
	bool boooling = 0;
	for (int i = x_index; i < x_index + num; i++)
		for (int f = y_index; f < y_index + num; f++)
			if (arr[f][i] != arr[y_index][x_index]) {
				boooling = 1;
				break;
			}
	if (boooling)
		segment(num, x_index, y_index);
	else if (arr[y_index][x_index] == -1)
		ct__1++;
	else if (arr[y_index][x_index] == 0)
		ct_0++;
	else if (arr[y_index][x_index] == 1)
		ct_1++;
}

void segment(int num, int x_index, int y_index) {
	judge(num / 3, 0 + x_index, 0 + y_index);
	judge(num / 3, num / 3 + x_index, 0 + y_index);
	judge(num / 3, num / 3 * 2 + x_index, 0 + y_index);
	judge(num / 3, 0 + x_index, num / 3 + y_index);
	judge(num / 3, num / 3 + x_index, num / 3 + y_index);
	judge(num / 3, num / 3 * 2 + x_index, num / 3 + y_index);
	judge(num / 3, 0 + x_index, num / 3 * 2 + y_index);
	judge(num / 3, num / 3 + x_index, num / 3 * 2 + y_index);
	judge(num / 3, num / 3 * 2 + x_index, num / 3 * 2 + y_index);
}

int main() {
	int size_;
	double N;
	bool boooling = 0;
	cin >> size_;
	for (int i = 0; i < size_; i++)
		for (int f = 0; f < size_; f++) {
			cin >> arr[f][i];
			if (f != 0 && i != 0)
				if (arr[f][i] != arr[0][0])
					boooling = 1;
		}
	N = log(size_) / log(3);
	if (boooling)
		segment(size_, 0, 0);
	else if (arr[0][0] == -1) {
		cout << "1\n0\n0";
		return 0;
	}
	else if (arr[0][0] == 0) {
		cout << "0\n1\n0";
		return 0;
	}
	else if (arr[0][0] == 1) {
		cout << "0\n0\n1";
		return 0;
	}


	cout << ct__1 << "\n" << ct_0 << "\n" << ct_1 << "\n";
}