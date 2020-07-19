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
bool arr[26] = { 0 };
vector<int>v[26];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - 'a'] = 1;
		v[str[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++)
		sort(begin(v[i]), end(v[i]));

	int cur = 0, sum = 0;
	for (int i = 0; i < 26; i++)
		if (arr[i] == 1) {
			for (int f = 0; f < v[i].size(); f++) {
				sum += abs(v[i][f] - cur);
				cur = v[i][f];
			}
		}
	cout << sum + str.length();
}