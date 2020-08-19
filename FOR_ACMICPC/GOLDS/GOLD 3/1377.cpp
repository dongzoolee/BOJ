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
#include<numeric>
using namespace std;
using ll = long long;
vector<int>v;
int cnt = 0;
bool chk[500001];
int n;
void pushing(vector<int>vec) {
	memset(chk, 0, sizeof(chk));
	vector<int>ret;
	int frt = 0, bk = 1;
	while (bk < vec.size()) {
		if (vec[frt] > vec[bk]) {
			ret.push_back(vec[bk]);
			frt = bk++;
			cnt++;
		}
		else {
			frt = bk++;
		}
	}
	if (vec.size() > 1 && vec[vec.size() - 2] <= vec[vec.size() - 1]) {
		ret.push_back(vec[vec.size() - 1]);
	}
	if (ret.size() == vec.size()) {
		return;
	}
	else {
		return pushing(ret);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	if (v.size() > 1) {
		pushing(v);
		cout << cnt + 1;
	}
	else {
		cout << 1;
	}
}