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
int arr[16], cnt = 0;

void judge() {
	cnt = 0;
	for (int i = 0; arr[i+1]!=0; i++) {
		for (int f = i + 1;arr[f]!=0; f++) {
			if (arr[i] * 2 == arr[f] || arr[f]*2==arr[i])
				cnt++;
		}
	}
	cout << cnt << "\n";
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i = 0;

	while (1) {
		cin >> arr[i++];
		if (arr[i - 1] == 0) { judge(); i = 0; }
		if (arr[i - 1] == -1)return 0;
	}
}