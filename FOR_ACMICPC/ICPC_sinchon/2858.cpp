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
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		if (a + b == (1 + i) * (1 + a / 2 - i)) {
			cout << max(1 + a / 2 - i, 1 + i) << " " << min(1 + a / 2 - i, 1 + i);
			return 0;
		}
	}
}