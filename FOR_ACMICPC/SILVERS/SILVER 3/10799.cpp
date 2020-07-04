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
vector<int> laser;
vector<int> left_;
int left_cnt = 0, rgt_cnt = 0 ,total =0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	int n = str.length();

	for (int i = 0; i < n; i++) {
		if (str[i] == '(' && str[i + 1] == ')') {
			laser.push_back(i++);
			continue;
		}

		if (str[i] == '(') {
			left_cnt++;
			left_.push_back(i);
		}
		else if (str[i] == ')') {
			rgt_cnt++;
			
			int counter = 0;
			for (int f = 0; f < laser.size(); f++)
				if (left_[left_.size() - 1] < laser[f] && laser[f] < i)
					counter++;
			if (counter != 0)
				counter++;
			left_.pop_back();
			total += counter;

			if (left_cnt == rgt_cnt) {
				laser.erase(laser.begin(), laser.end());
				left_.erase(left_.begin(), left_.end());
				left_cnt = rgt_cnt = 0;
			}
		}
	}
	cout << total;
}