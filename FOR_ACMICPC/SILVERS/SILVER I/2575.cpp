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
vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll m;
	cin >> m;

	//A 
	if (m % 3 == 0) {
		cout << m / 3;
	}
	else {
		cout << m / 3 + 1;
	}


	//B 소인수분해
	int tmp = m, cnt = 0;
	for (int i = 2; i <= tmp; i++) {
		while (tmp % i == 0) {
			if (i == 2)cnt++;
			tmp /= i;
			v.push_back(i);
		}
	}
	

	if (v.size() != 0) {
		if (cnt >= 2) {
			if (cnt % 2 == 0)
				cout << " " << v.size() - cnt / 2;
			else
				cout << " " << v.size() - cnt + cnt / 2 + 1;
		}
		else
			cout << " " << v.size();
	}
	else
		cout << " " << 1;
}