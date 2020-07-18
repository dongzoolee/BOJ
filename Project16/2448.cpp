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
#include <ctime>
using namespace std;
using ll = long long;
int chk = 0, n;
void print() {
	for (int f = 0; f < n; f++) {
		for (int i = n - 1 - f; i >= 0; i--)
			cout << ' ';


	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	print();
}