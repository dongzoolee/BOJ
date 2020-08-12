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
vector<ll>v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m,tmp, a;
	cin >> n >> m;
	tmp = n;
	while (tmp--) {
		cin >> a;
		v.push_back(a);
	}
	ll frt = 0, bk = 0;
	ll sum = v[0], cnt=0;
	ll limit = v.size() - 1;
	while (bk<limit) {
		if (sum < m) {
			sum += v[++bk];
		}
		else if (sum > m) {
			sum -= v[frt++];
		}
		else {
			cnt++;
			sum -= v[frt++];
		}
	}
	while (frt <= bk) {
		if (sum == m) {
			cnt++;
			sum -= v[frt++];
		}
		else if (sum > m) {
			sum -= v[frt++];
		}
		else if (sum < m) {
			break;
		}
	}
	cout << cnt;
}