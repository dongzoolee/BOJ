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
	vector <pair<int, int>> vec;
	bool checker[101] = { 0 };

	int main() {
		int w, h, x, y, p, counter = 0;
		cin >> w >> h >> x >> y >> p;

		for (int i = 0; i < p; i++) {
			int input1, input2;
			cin >> input1 >> input2;
			vec.push_back({ input1, input2 });
		}

		// 직사각형 안에 있는지 확인
		for (int i = 0; i < p; i++)
			if (vec[i].first >= x && vec[i].first <= x + w && vec[i].second >= y && vec[i].second <= y + h) {
				checker[i] = 1;
			}
		// 왼쪽 반원에 있는지 확인
		double h_half = h / 2;
		for (int i = 0; i < p; i++) {
			if (checker[i] == 0) {
				double dbl = ((double)vec[i].first - x) * ((double)vec[i].first - x) + ((double)vec[i].second - y - h_half) * ((double)vec[i].second - y - h_half);
				if (dbl <= h_half * h_half)
					checker[i] = 1;
			}
		}
		// 오른쪽 반원 있는지 확인
		for (int i = 0; i < p; i++) {
			if (checker[i] == 0) {
				double dbl = ((double)vec[i].first - x - w) * ((double)vec[i].first - x - w) + ((double)vec[i].second - y - h_half) * ((double)vec[i].second - y - h_half);
				if (dbl <= h_half * h_half)
					checker[i] = 1;
			}
		}
		for (int i = 0; i < p; i++) {
			if (checker[i] == 1)
				counter++;
		}
		cout << counter;
	}