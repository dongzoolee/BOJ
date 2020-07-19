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
	
	
	ll s, k;
	cin >> s >> k;

	vector<ll>v;
	ll quo, rem;
	quo = s / k;
	rem = s % k;

	ll result = 1;
	for (int i = 0; i < rem; i++)
		result *= (quo + 1);
	for (int i = 0; i < k-rem; i++)
		result *= quo;

	cout << result;
}