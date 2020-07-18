#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
ll n, arr[101][101], cnt = 0, total;

void bt(ll y, ll x, ll counter) {
	if (y == n - 1 && x == n - 1) { cnt++; return; }
	if (counter >= total) return;

	if (y + arr[y][x] < n)
		bt(y + arr[y][x], x, counter+arr[y][x]);
	if (x + arr[y][x] < n)
		bt(y, x + arr[y][x], counter + arr[y][x]);
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n;
	total = 2 * n - 2;

	for (ll i = 0; i < n; i++)
		for (ll f = 0; f < n; f++)
			cin >> arr[i][f];

	bt(0, 0, 0);
	cout << cnt;
}