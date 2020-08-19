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
#include <numeric>
using namespace std;
using ll = long long;
vector<int>pl;
vector<int>mi;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a;
	int zcnt = 0, onecnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			onecnt++;
		}
		else if (a > 0) {
			pl.push_back(a);
		}
		else if (a < 0) {
			mi.push_back(a);
		}
		else {
			zcnt++;
		}
	}
	int sum = 0;
	sort(pl.begin(), pl.end(), greater<>());
	sort(mi.begin(), mi.end());
	if (pl.size() % 2 == 0 && pl.size()) {
		for (int i = 0; i < pl.size() - 1; i += 2) {
			sum += pl[i] * pl[i + 1];
		}
	}
	else if (pl.size()) {
		if (pl.size() >= 3)
			for (int i = 0; i < pl.size() - 2; i += 2) {
				sum += pl[i] * pl[i + 1];
			}
		sum += pl[pl.size() - 1];
	}

	if (mi.size() % 2 == 0 && mi.size())
		for (int i = 0; i < mi.size() - 1; i += 2) {
			sum += mi[i] * mi[i + 1];
		}
	else if (mi.size() && zcnt) { // È¦¼ö && 0Á¸Àç
		if (mi.size() >= 3)
			for (int i = 0; i < mi.size() - 2; i += 2) {
				sum += mi[i] * mi[i + 1];
			}
	}
	else if (mi.size()) {
		if (mi.size() >= 3)
			for (int i = 0; i < mi.size() - 2; i += 2) {
				sum += mi[i] * mi[i + 1];
			}
		sum += mi[mi.size() - 1];
	}
	cout << sum + onecnt;
}