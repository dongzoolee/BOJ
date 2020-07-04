#include <iostream>
#include <stdio.h>
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
int n, tt, z, arr[21];
long long fac[21] = { 1, }, howmany, counter = 0;
vector <int> vec;
vector <int> vec_;

void factorial_2(int m) {
	if (m == n) { counter++; return; }
	if (m == n - 1) { if (vec_[0] > vec_[1]) counter += 2; else counter++; return; }
	int num = 0;
	for (int i = 1; i < n-m+1; i++)
		if (vec_[0] > vec_[i])
			num++;

	counter += num * fac[n - m];
	vec_.erase(vec_.begin());
	factorial_2(m+1);
}

void factorial(int m) {
	if (m == 0) return;
	long long hmy = howmany / fac[m];
	long long hmr = howmany % fac[m];
	if (howmany % fac[m] == 0) {
		cout << vec[hmy - 1] << " ";
		vec.erase(vec.begin() + hmy - 1);
		for (int i = vec.size() - 1; i >= 0; i--)
			cout << vec[i] << " ";
		return;
	}
	else {
		cout << vec[hmy] << " ";
		vec.erase(vec.begin() + hmy);
	}
	howmany = hmr;
	factorial(m-1);
}

int main() {
	cin >> n >> tt;
	for (int i = 1; i <= n; i++) {
		fac[i] = i * fac[i - 1];
		vec.push_back(i);
	}

	if (tt == 1) {
		cin >> howmany;
		if (howmany == 1 && n == 1) { cout << "1"; return 0; }
		for (int i = 2; i <= n; i++)
			if (fac[i - 1] <= howmany && howmany <= fac[i])
				z = i-1;
		for (int i = 0; i < n - z - 1; i++) {
			cout << vec[0] << " ";
			vec.erase(vec.begin() + 0);
		}
			
		factorial(z);
	}
	else {
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			vec_.push_back(input);
		}
		int i = 0;
		for (vector<int>::iterator it = vec_.begin(); it != vec_.end();) {
			if (*it == ++i)
				it = vec_.erase(it);
			else
				break;
		}
				factorial_2(i); // 1 2 3 ...sequence가 안 일치하는 순간의 숫자를 보내줌
				cout << counter;
	}
}