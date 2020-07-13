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
ll tenp[] = { 1, 10,100,1000,10000,100000,1000000 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k, result = 0;
	cin >> n >> k;
	for (ll i = 1; i <= k; i++) {
		ll len = (ll)log10(n * i) + 1, sum = 0, temp = n*i;
		for (int i = len - 1; i >= 0; i--) {
			sum += tenp[i] * (temp % 10);
			temp /= 10;
		}
		result = max(result, sum);
	}
	cout << result;
}