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
ll arr[100000];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	ll sq1 = (ll)pow(arr[n - 1], (double)1 / (n - 1));
	ll sq2 = sq1 + 1;
	ll sq3 = sq1 - 1;
	ll pw1 = (ll)pow(sq1, n - 1);
	ll pw2 = (ll)pow(sq2, n - 1);
	ll pw3 = (ll)pow(sq3, n - 1);
	ll cnt1 = 0, cnt2 = 0, cnt3  = 0;
	ll idx = n - 1;
	while (pw2 && idx >= 0) {
		cnt1 += abs(arr[idx--] - pw2);
		pw2 /= sq2;
	}
	idx = n - 1;
	while (pw1 && idx >= 0) {
		cnt2 += abs(arr[idx--] - pw1);
		pw1 /= sq1;
	}
	idx = n - 1;
	if (sq3 > 0) {
		while (pw3 && idx >= 0) {
			cnt3 += abs(arr[idx--] - pw3);
			pw3 /= sq3;
		}
		cout << min(cnt1, min(cnt2, cnt3));
	}
	else {
		cout << min(cnt1,cnt2);
	}
}