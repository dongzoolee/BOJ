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

int main() {
	int tc, a, b;
	cin >> tc;
	for (int f = 0; f < tc; f++) {
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}


}