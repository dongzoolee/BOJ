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
int counter = 0;
long L, R, L_len, R_len, L_ten, R_ten, L_og, R_og;
bool bol = 0;
void samelen();

void difflen() {
	return;
}

void samelen() {
	if (L / L_ten == R / R_ten) { // 두 숫자의 대가리가 같다.
		if (L / L_ten == 8)// 대가리가 8
			if (L == L_og)
				counter++;
			else if (bol == 0)
				counter++;
	}
	else
		bol = 1;
	L %= L_ten, R %= R_ten, L_ten /= 10, R_ten /= 10;
	if (L_ten != 0)
		samelen();
}

int main() {
	cin >> L >> R;
	long min_ = min(L, R), max_ = max(L, R);
	L = min_, R = max_; // L<R로 정렬
	L_og = L, R_og = R;
	L_len = (long)log10(L)+ 1, R_len = (long)log10(R) + 1, L_ten = (long)pow(10, L_len - 1), R_ten = (long)pow(10, R_len -1);
	if (L_len != R_len) // 두 문자열 길이가 다르다
		difflen();
	else // 두 문자열 길이가 같다
		samelen();

	cout << counter;
}