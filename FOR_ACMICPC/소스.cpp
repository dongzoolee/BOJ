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
#include<numeric>
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
vector<int>vec;
vector<int>laser;
int sum = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			vec.push_back(-1);
		}
		else {
			if (vec.back() == -1) {
				// 레이저O
				vec.pop_back();
				vec.push_back(2); // 2 = laser
				laser.push_back(vec.size()-1);
			}
			else {
				vec.push_back(-2);
			}
		}
	}
	stack<int>stk;
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == -1) {
			stk.push(i);
		}
		if (vec[i] == -2) {
			for (int f = 0; f < laser.size(); f++)
				if (stk.top() + 1 <= laser[f] && laser[f] < i)
					cnt++;
				else if (laser[f] >= i)
					break;
			sum += cnt + 1;
			cnt = 0;
			stk.pop();
		}
	}
	cout << sum;
}