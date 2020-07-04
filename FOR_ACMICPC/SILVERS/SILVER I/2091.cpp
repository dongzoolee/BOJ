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
int cent[4] = { 1,5,10,25 }, a[4], max_ = 0, xx;
//dp라고한다...
void calculate(int x, int i, int counter, vector<int> v) {
	if (i == 4 && x != 0) return;

	if (x <= 0 || counter == 10000) {
		if (x < 0)
			return;
		else {
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << " ";
			exit(0);
		}
	}
	else {
		for (int h = a[i]; h >= 0; h--)
			if (x - h * cent[i] >= 0) {
				v[i] = h;
				calculate(x - h * cent[i], i + 1, counter + h, v);
			}
	}
}

int main() {
	vector<int> vec(4, 0);
	cin >> xx >> a[0] >> a[1] >> a[2] >> a[3];

	calculate(xx, 0, 0, vec);
}