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
long long gcd(long long k, long long l) { return l ? gcd(l, k % l) : k;}
int main() {
	long long n, m;
	cin >> n >> m;
	for (long long i = 0; i < gcd(n, m); i++)
		cout << "1";

}