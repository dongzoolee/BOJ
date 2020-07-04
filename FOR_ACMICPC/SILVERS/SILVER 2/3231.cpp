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
vector <pair<int, int>> num;

int main() {
	int n, input, counter = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		num.push_back({ i,input });

	}

	sort(begin(num), end(num), [](auto a, auto b) {
		return a.second < b.second;
		});

	for (int i = 1; i < n; i++)
		if (num[i].first < num[i - 1].first)
			counter++;

	cout << counter;
}