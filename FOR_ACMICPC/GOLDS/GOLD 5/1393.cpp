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
#include <float.h>
using namespace std;
int baduk[201][201];
int gcd(int k, int l) { return l ? gcd(l, k % l) : k; }

int main() {
	int dest_x, dest_y, curr_x, curr_y, mov_per_sec_x, mov_per_sec_y, temp, min_x, min_y;
	double min = DBL_MAX;
	cin >> dest_x >> dest_y >> curr_x >> curr_y >> mov_per_sec_x >> mov_per_sec_y;
	int gcd_temp = gcd(mov_per_sec_x, mov_per_sec_y);

	if (mov_per_sec_y == 0) {
		if (mov_per_sec_x > 0) {
			if (curr_x < dest_x) {
				cout << dest_x << " " << curr_y;
				return 0;
			}
			else
				cout << curr_x << " " << curr_y;
		}
		else
			

		return 0;
	}
	else if (mov_per_sec_x == 0) {

		return 0;
	}

	if (gcd_temp != 1) {
		mov_per_sec_x /= gcd_temp;
		mov_per_sec_y /= gcd_temp;
	}

	for (int i = curr_x; i < 101; i++) {
		if (abs(i) % mov_per_sec_x == 0) {
			temp = (i - curr_x) / mov_per_sec_x * mov_per_sec_y + curr_y;
			if (fabs((double)pow(i - dest_x, 2) + (double)pow(temp - dest_y, 2)) < min && temp < 101) {
				min = fabs((double)pow(i - dest_x, 2) + (double)pow(temp - dest_y, 2));
				min_x = i;
				min_y = temp;
			}
		}
	}
	cout << min_x << " " << min_y;
}