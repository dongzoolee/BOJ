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
int arr[100000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// two pointer
	int h = 0, t = n - 1, idx_h, idx_t, min_ = INT_MAX;
	while (h != t) {
		if (abs(arr[h] + arr[t]) < min_) {
			min_=abs(arr[h] + arr[t]);
			idx_h = h, idx_t = t;
		}

	}
	cout <<
}