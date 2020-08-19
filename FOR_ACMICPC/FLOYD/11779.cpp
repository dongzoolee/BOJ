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
ll route[1001][1001];
ll mid[1001][1001];
ll a, b, c;
ll n, m;
void floyd() {
	for (int h = 1; h <= n; h++)
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (route[i][h] >= 0 && route[h][j] >= 0 && route[i][j] >= 0) {
					if (route[i][j] > route[i][h] + route[h][j]) {
						route[i][j] = route[i][h] + route[h][j];
						mid[i][j] = mid[h][j];
					}
				}
				else if (route[i][h] >= 0 && route[h][j] >= 0) {
					route[i][j] = route[i][h] + route[h][j];
					mid[i][j] = mid[h][j];
				}
			}
		}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(route, -1, sizeof(route));
	memset(mid, -1, sizeof(mid));
	while (m--) {
		cin >> a >> b >> c;
		// 아.........깜빡하지 말자ㅜㅜㅜㅜ
		// a->b로 가는 간선이 하나만 있는게 아니다...
		if (route[a][b] == -1)
			route[a][b] = c;
		else
			route[a][b] = min(route[a][b], c);
		mid[a][b] = a;
	}
	cin >> a >> b;
	floyd();
	if (route[a][b] != -1)
		cout << route[a][b] << '\n';
	else
		cout << 0 << '\n' << 0;

	stack<ll>path;
	if (a != b)
		for (int i = a; i <= a; i++) {
			for (int j = b; j <= b; j++) {
				if (mid[i][j] == -1) continue;
				//cout << i << "부터" << j<<' ';
				int pre = j;
				path.push(j);
				while (i != mid[i][pre]) {
					pre = mid[i][pre];
					path.push(pre);
				}
				cout << path.size() + 1 << '\n';
				cout << i;
				while (!path.empty()) {
					cout << ' ' << path.top();
					path.pop();
				}
				cout << '\n';
			}
		}
	else
		cout << 1<<'\n'<<a;

}