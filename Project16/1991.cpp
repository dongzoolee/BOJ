#include <queue>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
using ll = long long;
char arr[26][2];
void jw(int root) {
	cout << (char)(root+'A');
	if (arr[root][0]!='.') {
		jw(arr[root][0] - 'A');
	}
	if (arr[root][1] != '.') {
		jw(arr[root][1] - 'A');
	}
}

void juw(int root) {
	if (arr[root][0] != '.')
		juw(arr[root][0] - 'A');
	cout << (char)(root + 'A');
	if (arr[root][1] != '.')
		juw(arr[root][1] - 'A');
}

void huw(int root) {
	if (arr[root][0] != '.')
		huw(arr[root][0] - 'A');
	if (arr[root][1] != '.')
		huw(arr[root][1] - 'A');
	cout << (char)(root + 'A');
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char input;
		cin >> input;
		input -= 'A';
		for (int f = 0; f < 2; f++) {
			cin >> arr[input][f];
		}
	}
	jw(0);
	cout << "\n";
	juw(0);
	cout << "\n";
	huw(0);
}