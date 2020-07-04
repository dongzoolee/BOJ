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
int N, arr[100001][3], min_ = 0, max_ = 0, x, y, z, a, b, c;
queue<pair<pair<int, int>, int>> till_min;
queue<pair<pair<int, int>, int>> till_max;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int f = 0; f < 3; f++)
			cin >> arr[i][f];
	till_min.push({ { arr[0][0],arr[0][1] }, arr[0][2] });
	till_max.push({ { arr[0][0],arr[0][1] }, arr[0][2] });
	// max, min 둘 다 기본 arr값으로 초기화 해준다.

	for (int i = 1; i < N; i++) {
		for (int f = 0; f < 3; f++) {
			if (f == 0) {
				x = min(till_min.front().first.first + arr[i][0], till_min.front().first.second + arr[i][0]);
				a = max(till_max.front().first.first + arr[i][0], till_max.front().first.second + arr[i][0]);
			}
			else if (f == 1) {
				y = min({ till_min.front().first.first + arr[i][1], till_min.front().first.second + arr[i][1], till_min.front().second + arr[i][1] });
				b = max({ till_max.front().first.first + arr[i][1], till_max.front().first.second + arr[i][1], till_max.front().second + arr[i][1] });
			}
			else {
				z = min(till_min.front().first.second + arr[i][2], till_min.front().second + arr[i][2]);
				c = max(till_max.front().first.second + arr[i][2], till_max.front().second + arr[i][2]);
			}
		}
		
		till_min.pop();
		till_max.pop();
		till_min.push(make_pair(make_pair(x, y), z));
		till_max.push(make_pair(make_pair(a, b), c));
	}
	min_ = min({ till_min.front().first.first,till_min.front().first.second,till_min.front().second });
	max_ = max({ till_max.front().first.first,till_max.front().first.second,till_max.front().second });

	cout << max_ << " " << min_;

}