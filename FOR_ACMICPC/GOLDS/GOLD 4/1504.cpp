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
ll arr[801][801] = { 0 };
ll n, e;
ll INF = 1000000000;
// FLOID overflow 조심
// long long 사용하기
void floid() {
	for (ll h = 1; h <= n; h++)
		for (ll i = 1; i <= n; i++)
			for (ll f = 1; f <= n; f++)
				if (arr[i][f] > arr[i][h] + arr[h][f])
					arr[i][f] = arr[i][h] + arr[h][f];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b, c;
	cin >> n >> e;
	for (ll i = 0; i < e; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] == 0) {
			arr[a][b] = c;
			arr[b][a] = c;
		}
		else {
			arr[a][b] = min(c, arr[a][b]);
			arr[b][a] = min(c, arr[b][a]);
		}
	}
	cin >> a >> b;
	for (ll i = 1; i <= n; i++)
		for (ll f = 1; f <= n; f++)
			if (arr[i][f] == 0 && i != f)
				arr[i][f] = INF;
	floid();
	if (min(arr[1][a] + arr[a][b] + arr[b][n], arr[1][b] + arr[b][a] + arr[a][n]) >= INF)
		cout << -1;
	else
		cout << min(arr[1][a] + arr[a][b] + arr[b][n], arr[1][b] + arr[b][a] + arr[a][n]);
}