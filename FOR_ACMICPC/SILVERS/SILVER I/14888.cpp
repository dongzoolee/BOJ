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
int n, num[20], equ[4], max_ = INT_MIN, min_ = INT_MAX;

void recur(int numb, int equa, int sum, vector<int> v) {
	if (v[equa] == 0 && numb != n) return;
	if (numb == n) {
		max_ = max(max_, sum);
		min_ = min(min_, sum);
		return;
	}
	if (equa == 0) {
		v[equa]--;
		sum += num[numb];
	}
	if (equa == 1) {
		v[equa]--;
		sum -= num[numb];
	}
	if (equa == 2) {
		v[equa]--;
		sum *= num[numb];
	}
	if (equa == 3) {
		v[equa]--;
		sum /= num[numb];
	}
	recur(numb + 1, 0, sum, v);
	recur(numb + 1, 1, sum, v);
	recur(numb + 1, 2, sum, v);
	recur(numb + 1, 3, sum, v);
}

int main() {
	vector<int>vec(4, 0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> vec[i];

	recur(1, 0, num[0], vec);
	recur(1, 1, num[0], vec);
	recur(1, 2, num[0], vec);
	recur(1, 3, num[0], vec);
	cout << max_ << "\n" << min_;
}