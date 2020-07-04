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

int gcd(int k, int l) { return l ? gcd(l, k % l) : k; }
int lcm(int k, int l) { return k / gcd(k, l) * l; }

int main() {
	int arr[2][2];

	for (int i = 0; i < 2; i++)
		for (int f = 0; f < 2; f++)
			cin >> arr[i][f];

	int lll = lcm(arr[0][1], arr[1][1]);
	int bunja = lll / arr[0][1] * arr[0][0] + lll / arr[1][1] * arr[1][0];
	int gcdgcd = gcd(bunja, lll);
	if (gcdgcd == 1)
		cout << bunja << " " << lll;
	else
		cout << bunja / gcdgcd << " " << lll / gcdgcd;
}