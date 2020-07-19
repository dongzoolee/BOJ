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
vector<string>alp[26];
int chk[26], cnt = 0;
int main() {
	for (int i = 0; i < 26; i++) chk[i] = -1;
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, z = 0;
	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (chk[input[0] - 'a'] == -1) {
			alp[z].push_back(input);
			chk[input[0] - 'a'] = z++;
		}
		else
			alp[chk[input[0] - 'a']].push_back(input);
	}

	for (int i = 0; i < 26; i++)
		sort(alp[i].begin(), alp[i].end());

	for (int i = 0; i < 26; i++)
		for (int f = 0; f < alp[i].size()-1 && alp[i].size() != 0; f++) {
			if (alp[i][f] == alp[i][f + 1].substr(0, alp[i][f].size())) {
				cnt++;
				break;
			}
		}
	cout << n - cnt;
}