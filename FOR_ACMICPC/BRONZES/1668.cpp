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
	int tc, trophies[51], max = 0, left_counter = 0, right_counter = 0;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> trophies[i];
		if (max < trophies[i]) {
			max = trophies[i];
			left_counter++;
		}
	}
	max = 0;
	for (int i = tc-1; i >= 0; i--) {
		if (max < trophies[i]) {
			max = trophies[i];
			right_counter++;
		}
	}
	cout << left_counter << "\n" <<right_counter;
}