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
int arr[49], n;

void bt(vector<int>v, int idx) {
	v.push_back(arr[idx]);

	if (v.size() == 6) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i]<<" ";
		cout << "\n";
		return;
	}

	for (int i = idx + 1; i < n; i++)
		bt(v, i);
}

int main() {
	cin >> n;
	while (n!=0) {
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		vector<int>vec;
		for (int i = 0; i <= n - 6; i++)
			bt(vec, i);
		cout << "\n";
		cin >> n;
	}
}