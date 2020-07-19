#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
using longs = long long;
priority_queue <int>q; // max hip
priority_queue<int, vector<int>, greater <int>> qu; // min hip

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input == 0) {
			if (qu.empty())
				cout << 0 << '\n';
			else {
				cout << qu.top() << '\n';
				qu.pop();
			}
		}
		else {
			qu.push(input);
		}
	}

}