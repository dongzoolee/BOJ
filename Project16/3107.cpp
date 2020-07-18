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
vector<vector<char>>v;
int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	int z = 0, zeroplace = -1;
	bool bol = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ':') {
			if (i != 0)
				z++;
			if (bol==0)
				if (str[i + 1] == ':') {
					zeroplace = z;
					i++;
					bol = 1;
				}
		}
		else {
			if (z == v.size())
				v.push_back(vector<char>());
			v[z].push_back(str[i]);
		}
	}

	int cnt = 0;
	if (zeroplace == -1) {
		for (int i = 0; i < 8; i++) {
			if (v[i].size() != 4) {
				for (int f = 0; f < 4 - v[i].size(); f++)
					cout << "0";
				for (int f = 0; f < v[i].size(); f++)
					cout << v[i][f];
			}
			else {
				for (int f = 0; f < v[i].size(); f++)
					cout << v[i][f];
			}
			if (i != 7)
				cout << ":";
		}
	}
	else {
		for (int i = 0; cnt<8; i++) {
			if (i==z) {
				for (int i = 0; i < 8-v.size(); i++) {
					cout << "0000";
					cnt++;
					if (cnt<8)
						cout << ":";
				}
			}
			if (i < v.size()) {
				if (v[i].size() != 4) {
					for (int f = 0; f < 4 - v[i].size(); f++)
						cout << "0";
					for (int f = 0; f < v[i].size(); f++)
						cout << v[i][f];
					cnt++;
				}
				else {
					for (int f = 0; f < v[i].size(); f++)
						cout << v[i][f];
					cnt++;
				}
			}
				if (cnt < 8)
					cout << ":";
				if (cnt == 8)
					break;
		}
	}
}