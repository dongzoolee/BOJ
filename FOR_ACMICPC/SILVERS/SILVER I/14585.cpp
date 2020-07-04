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
vector <pair<int, int>> vec;

int main() {
	int num;
	cin >> num;
	for (int i = num; i > 0; i--) {
		for (int f = i; f > 0; f--)
			cout << "*";
		cout << "\n";
	}
}

