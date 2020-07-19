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
string str;
vector<string>st[26];
int idx[2][2], chk[26];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 26; i++)chk[i] = -1; // for line : 25

	int n, max_ = 0,z=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (chk[str[0] - 'a'] == -1) { // if it's not already used
			st[z].push_back(str);
			chk[str[0] - 'a'] = z++;
		}
		else
			st[chk[str[0] - 'a']].push_back(str);
	}

	for (int h = 0; h < 26; h++) // alphabet
		for (int i = 0; i < st[h].size()-1 && st[h].size()!=0; i++) { // string index
			char head = st[h][i][0];
			for (int f = i + 1; f < st[h].size() && st[h][f][0] == head; f++) { //moving index
				for (int z = 1; z <= min(st[h][i].length(), st[h][f].length()); z++)
					if (st[h][i].substr(0, z) == st[h][f].substr(0, z)) { // checking duplication
						if (z > max_) {
							idx[0][0] = h, idx[0][1] = i, idx[1][1] = f;
							max_ = max(max_, z);
						}
					}
					else break;
			}
		}
	cout << st[idx[0][0]][idx[0][1]] << "\n" << st[idx[0][0]][idx[1][1]];
}