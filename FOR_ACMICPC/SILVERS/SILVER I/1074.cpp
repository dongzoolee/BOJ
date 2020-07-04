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
int N, r, c, hang = 0, nyul = 0, adding = 0;

int decide_area(int sze, int hng, int nyl) {
	if ((int)pow(2, sze - 1) >= hng + 1 && (int)pow(2, sze - 1) >= nyl + 1) {
		return 1;
	}
	else if ((int)pow(2, sze - 1) >= hng + 1 && (int)pow(2, sze - 1) < nyl + 1) {
		nyul -= (int)pow(2, sze - 1);
		adding += (int)pow(2, sze + sze - 2);
		return 2;
	}
	else if ((int)pow(2, sze - 1) < hng + 1 && (int)pow(2, sze - 1) >= nyl + 1) {
		hang -= (int)pow(2, sze - 1);
		adding += (int)pow(2, sze + sze - 2) * 2;
		return 3;
	}
	else {
		hang -= (int)pow(2, sze - 1);
		nyul -= (int)pow(2, sze - 1);
		adding += (int)pow(2, sze + sze - 2) * 3;
		return 4;
	}
}

int main() {
	cin >> N >> r >> c;
	hang = r;
	nyul = c;

	while (N!=0) {
		decide_area(N, hang, nyul);
		N--;
	}

	cout << adding;
}