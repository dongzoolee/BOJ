#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str1, str2;
	cin >> str1;
	cin >> str2;
	for (int i = 0; i < 100000; i++) {
		int st = (str1[i] - '0') & (str2[i] - '0');
		cout << st;
	}
	cout << '\n';
	for (int i = 0; i < 100000; i++) {
		int st = (str1[i] - '0') | (str2[i] - '0');
		cout << st;
	}
	cout << '\n';
	for (int i = 0; i < 100000; i++) {
		int st = (str1[i] - '0') ^ (str2[i] - '0');
		cout << st;
	}
	cout << '\n';
	for (int i = 0; i < 100000; i++)
		if (str1[i] == '0')
			cout << 1;
		else
			cout << 0;
	cout << '\n';
	for (int i = 0; i < 100000; i++)
		if (str2[i] == '0')
			cout << 1;
		else
			cout << 0;
}