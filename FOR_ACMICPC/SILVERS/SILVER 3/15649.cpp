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
using longs = long long;
int n, k, start;

void manimanitoktok(vector<int> v, int st) {
	v.push_back(st);
	if (v.size() == k) {
		for (int i = 0; i < k; i++) {
			cout << v.front() << " ";
			v.erase(v.begin());
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (v.end() == find(v.begin(), v.end(), i))
			manimanitoktok(v, i);
	}
}

int main() {
	cin >> n >> k;
	vector<int> vec;

	for (int i = 1; i <= n; i++) {
		manimanitoktok(vec, i);
	}
}