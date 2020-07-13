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
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
int arr[50][50], min_ = INT_MAX, n, m;
bool chk[13] = { 0 };
vector<pair<int, int>>chick;
vector<pair<int, int>>house;

void judge() {
	int temp = 0;
	for (int f = 0; f < house.size(); f++) {
		int dist = INT_MAX;
		for (int i = 0; i < chick.size(); i++) {
			if (chk[i] == 1)
				dist = min(dist, abs(chick[i].first - house[f].first) + abs(chick[i].second - house[f].second));
		}
		temp += dist;
	}
	min_ = min(temp, min_);
}

void split(int st, int cnt) {
	if (cnt == m) return judge();
	else if (cnt > m || st >= chick.size()) return;

	for (int i = st; i < chick.size(); i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			split(i + 1, cnt + 1); // bt할때,,,,조심하자,,,,
			chk[i] = 0;
		}
	}
}
int main() {
	//clock_t startTime = clock();
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input1.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++) {
			cin >> arr[i][f];
			if (arr[i][f] == 2)
				chick.push_back({ i, f });
			if (arr[i][f] == 1)
				house.push_back({ i, f });
		}
	split(0, 0);
	cout << min_;
	//clock_t endTime = clock();
	//cout << "\n걸린시간 : " << endTime - startTime <<"ms";
}