#include <iostream>
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
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cout << '*';
	for (int i = 0; i < 2 * n - 3; i++)
		cout << ' ';
	for (int i = 0; i < n; i++)
		cout << '*';
	cout << '\n';
	for (int f = 1; f < n; f++) {
		for (int i = 0; i < f; i++)
			cout << ' ';
		cout << '*';
		for (int i = 0; i < n - 2; i++)
			cout << ' ';
		if (f != n - 1) {
			cout << '*';
			for (int i = 0; i < 2 * n - 3 - f * 2; i++)
				cout << ' ';
			cout << '*';
		}
		else cout << '*';
		for (int i = 0; i < n - 2; i++)
			cout << ' ';
		cout << '*' << '\n';
	}

	for (int f = n-2; f >0; f--) {
		for (int i = 0; i < f; i++)
			cout << ' ';
		cout << '*';
		for (int i = 0; i < n - 2; i++)
			cout << ' ';
		if (f != n - 1) {
			cout << '*';
			for (int i = 0; i < 2 * n - 3 - f * 2; i++)
				cout << ' ';
			cout << '*';
		}
		else cout << '*';
		for (int i = 0; i < n - 2; i++)
			cout << ' ';
		cout << '*' << '\n';
	}
	for (int i = 0; i < n; i++)
		cout << '*';
	for (int i = 0; i < 2 * n - 3; i++)
		cout << ' ';
	for (int i = 0; i < n; i++)
		cout << '*';
}