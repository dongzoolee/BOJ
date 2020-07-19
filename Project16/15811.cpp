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
#include <ctime>
#include <numeric>  
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
int chk[26] = { 0 }, btchk[26] = { 0 }, contain[26] = { 0 };

int sum = 0;
string str[3];
vector<pair<int, int>>v;
void cal() {
	int result[20] = { 0 };
	int max_ = max(str[0].length(), str[1].length());
	for (int i = 0; i < max_; i++) {
		if (str[0].length() - 1 >= i) {
			result[i] += contain[str[0][i]-'A'];
		}
		if (str[1].length() - 1 >= i) {
			result[i] += contain[str[1][i]-'A'];
		}
		if (result[i] >= 10) {
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	result[max_] += result[max_ - 1] / 10;
	result[max_ - 1] %= 10;

	for (int f = 0; f < str[2].length(); f++) {
		if (result[f] != contain[str[2][f] - 'A'])
			return;
	}
	cout << "YES";
	exit(0);
}
void bt(int idx, int cnt) {
	if (cnt == sum) return cal();

	for (int i = 0; i < 10; i++) {
		if (btchk[i] == 0) {
			contain[v[idx].first] = i;
			btchk[i] = 1;
			bt(idx + 1, cnt + 1);
			btchk[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 3; i++) cin >> str[i];

	for (int f = 0; f < 3; f++)
		for (int i = 0; i < str[f].length(); i++)
			chk[str[f][i] - 'A'] = 1; // 있는 문자만 chk
	for (int i = 0; i < 26; i++)
		if (chk[i] == 1)
			v.push_back({ i, 0 });
	sum = accumulate(chk, chk + 26, sum);

	for (int i = 0; i < 3; i++)
		reverse(str[i].begin(), str[i].end());
	bt(0, 0);
	cout << "NO";
}