#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;

int gcd(int k, int l) { return l ? gcd(l, k % l) : k; }
int lcm(int k, int l) { return k / gcd(k, l) * l; }

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}
}