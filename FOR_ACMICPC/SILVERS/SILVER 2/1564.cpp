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

int main() {
	long long n, nine = 36288, zeropoint = 0;
	cin >> n;

	for (long long i = 10; i <= n; i++) {
		long long x = nine * i;
		while (x % 10 == 0) {
			x /= 10;
			zeropoint++;
		}
		nine = x % 100000000;
	}
	if ((long long)log10(nine % 100000) <= 3) {
		for (long long i = 1; i < 5 - (long long)log10(nine % 100000); i++)
			cout << "0";
		cout << nine % 100000;
	}
	else
		cout << nine % 100000;
}