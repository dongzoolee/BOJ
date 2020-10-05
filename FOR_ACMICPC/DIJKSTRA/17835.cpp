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
#define MX 60'000'000'000;
vector<pair<ll, ll>>v[100001];
vector<ll>goal;
bool chk[100001] = { 0 };
ll dist[100001];
ll ans[100001];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
void dijk() {
	while (!q.empty()) {
		ll d = q.top().first, cur = q.top().second;
		q.pop();

		if (dist[cur] < d) continue;
		// 비교할 필요 없는거 아닌가?
		// q.top().first에는 dist[cur]를 저장했는데?
		// -> 큐에서 자기 순서가 돌아올 때까지
		// dist[cur]는 계속 변한다. 가능한한 최솟값으로
		// 그러니까 저걸 해줘야 시간단축된다.

		for (ll i = 0; i < v[cur].size(); i++) {
			ll d = v[cur][i].first, next = v[cur][i].second;
			if (chk[next]) continue;
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				q.push({ dist[next],next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		v[b].push_back({ c,a });
	}
	fill(dist, dist + 100001, 60'000'000'000); // ?
	while (k--) {
		cin >> a;
		dist[a] = 0;
		q.push({ 0,a });
		chk[a] = 1;
	}
	dijk();
	pair<ll, ll>out = { 0,0 };
	for (ll f = 1; f <= n; f++) {
		if (dist[f] != 60'000'000'000)
			if (out.first < dist[f])
				out = { dist[f],f };
	}
	cout << out.second << '\n' << out.first;
}