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
int arr[3][2];
int gcd(int k, int l) { return l ? gcd(l, k%l) : k; }

void crossp() {
	int cr = (arr[1][0] - arr[0][0])*(arr[2][1] - arr[0][1]) - (arr[2][0] - arr[0][0])*(arr[1][1] - arr[0][1]);
	if (cr > 0) {
		cout << 1;
	}
	else if (cr < 0) {
		cout << -1;
	}
	else
		cout << 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 3; i++)
		cin >> arr[i][0] >> arr[i][1];

	crossp();
}