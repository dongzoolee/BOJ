#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
ll arr[2049][2049];
int two[1025];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 2049; i++)
		arr[i][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i < 2049; i++)
		for (int f = 0; f <= i; f++)
			arr[i][f] = (arr[i - 1][f] + arr[i - 1][f - 1]) % 1'000'000'007;

	ll h;
	cin >> h;
	ll cur = 2, res = 1;
	two[0] = 1;
	for (int i = 2; i <= h; i++) {
		cur += (ll)pow(2, i);
		ll tmp = 1;
		for (int f = 0; f < (ll)pow(2, h - i); f++) tmp = tmp * arr[cur][cur / 2] % 1'000'000'007;
		res = res % 1'000'000'007 * tmp % 1'000'000'007;
	}
	ll tmp1 = 1;
	for (int i = 1; i <= (ll)pow(2, h - 1); i++)
		tmp1 = tmp1 * 2 % 1'000'000'007;
	res = (res % 1'000'000'007 * tmp1) % 1'000'000'007;
	cout << res % 1'000'000'007;
}