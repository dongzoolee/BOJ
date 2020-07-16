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
int dp[1001][1001] = { 0 };
string str[2];
vector<char>v;
void findingmax() {
	bool chky[1001] = { 0 }, chkx[1001] = { 0 };
	int vl = dp[str[0].length()][str[1].length()];
	for (int i = str[0].length(); i > 0; i--)
		for (int f = str[1].length(); f > 0; f--) {
			if (dp[i][f] > dp[i - 1][f] && dp[i][f] > dp[i][f - 1] && dp[i][f] == vl && chky[i]==0 && chkx[f]==0) {
				v.push_back(str[0][i - 1]);
				chky[i] = 1, chkx[f] = 1;
				vl--;
			}
		}
}
void lcs() {
	for (int i = 1; i <= str[0].length(); i++)
		for (int f = 1; f <= str[1].length(); f++)
			if (str[0][i - 1] == str[1][f - 1]) dp[i][f] = dp[i - 1][f - 1] + 1;
			else dp[i][f] = max(dp[i - 1][f], dp[i][f - 1]);

	findingmax();
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str[0] >> str[1];

	lcs();
	cout << v.size() << "\n";
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
	return 0;
}