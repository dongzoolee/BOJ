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
int K;

void recursion(int sum, int length, int current_K) {
	for (int i = length;; i++)
		if (sum + (int)pow(2, i) < current_K)
			sum += (int)pow(2, i);
		else {
			length = i;
			break;
		}

	if (current_K <= sum + (int)pow(2, length - 1)) {
		cout << "4";
		current_K -= (int)pow(2, length - 1);
	}
	else {
		cout << "7";
		current_K -= 2 * (int)pow(2, length - 1);
	}

	
	if (length != 1)
		recursion(sum - (int)pow(2, length - 1), length - 1, current_K);
}

int main() {
		cin >> K;

		recursion(0, 1, K);
}