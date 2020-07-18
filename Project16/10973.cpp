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
#include <ctime>
using namespace std;
using ll = long long;
int arr[10000];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i-1] = i;
		cout << i << ' ';
	}
	cout << '\n';
	while (next_permutation(arr, arr + n) != 0) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

}