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
int len, total, lastidx;
vector<char>v;
void distrib() {
	total -= (len - 1);
	for (int i = len - 1; i >= 0; i--) {
		if (total > 26 && i == len-1) {
			v.push_back(26+'A'-1);
			total -= 26;
		}
		else if (total <= 26 && i == len - 1) {
			v.push_back(total + 'A' - 1);
			lastidx = i;
			break;
		}
		else if (total + 1 > 26) {
			v.push_back('Z');
			total -= 25;
		}
		else if (total + 1  <= 26) {
			v.push_back(total +'A');
			lastidx = i;
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> len >> total;

	if (total<len || len * 26 < total) {
		cout << "!";
		return 0;
	}
	distrib();

	for (int i = 0; i < lastidx; i++) {
		cout << "A";
	}
	for (int i = len - lastidx - 1; i >=0 ; i--) {
		cout << v[i];
	}
}