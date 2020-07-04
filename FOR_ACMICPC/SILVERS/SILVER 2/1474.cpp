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
	int N, M, len_sum = 0, _counter[102] = { 0 };
	bool is_upper[102] = { 0 };
	string str[101];
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
		M -= str[i].length();
		if (65 <= str[i].at(0) && str[i].at(0) <= 90)
			is_upper[i] = 1;
	}
	int quotient = M / (N - 1);
	int remainder = M % (N - 1);
	for (int i = 1; i < N; i++) {
		if (is_upper[i] == 0 && remainder != 0) {	//소문자라면
			_counter[i]++;
			remainder--;
		}
	}
	if (remainder != 0)
		for (int i = N - 1; i > 0 && remainder != 0; i--) {
			_counter[i]++;
			remainder--;
		}

	for (int i = 0; i < N; i++) {
		if (i != 0)
			for (int f = 0; f < _counter[i] + quotient; f++)
				cout << "_";
		cout << str[i];
	}

}