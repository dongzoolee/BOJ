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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1;; i++) {
		int len = (int)log10(i) + 1, temp = i;
		for (int f = 0; f < len - 2; f++) {
			if (temp % 1000 == 666) { cnt++; break; }
			temp /= 10;
		}
		if (cnt == n) { cout << i; return 0; }
	}
}