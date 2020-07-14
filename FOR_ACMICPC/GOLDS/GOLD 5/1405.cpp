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
int n;
double inp[4], d[4], sum = 0;
vector<int>cnt;
void move(vector<int>v, vector<vector<int>>chk) {
	int arr[4] = { 0 };
	pair<int, int> cur = { 14,14 };
	chk[14][14] = 1;
	for (int i = 0; i < v.size(); i++) {
		arr[v[i]]++;
		if (v[i] == 0) cur.first++;
		if (v[i] == 1) cur.second++;
		if (v[i] == 2) cur.first--;
		if (v[i] == 3) cur.second--;
		if (chk[cur.first][cur.second] == 1 && i == v.size() - 1) {
			double tmp = 1;
			for (int f = 0; f < 4; f++) if (arr[f] != 0) tmp *= (double)pow(d[f], arr[f]);
			sum += tmp;
			return;
		}
		chk[cur.first][cur.second] = 1;
	}
}
// 이 과정때문에 시간 부족
void split(vector<int>v, vector<vector<int>>chk, int lim) {
	if (v.size() == lim) { move(v, chk); return; }

	for (int f = 0; f < 4; f++) {
		v.push_back(f);
		split(v, chk, lim);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> inp[0] >> inp[1] >> inp[2] >> inp[3];
	for (int i = 0; i < 4; i++) d[i] = inp[0] / 100;
	vector<int>dir;
	vector<vector<int>>chk;
	chk.assign(29, vector<int>(29, 0));
	cnt.assign(4, 0);
	split(dir, chk, n);
	cout << 1 - sum;
}