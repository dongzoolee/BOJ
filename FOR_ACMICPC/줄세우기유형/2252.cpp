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
vector<pair<int,int>>v;
int tmp[32001];
int res[32001];
int box[32001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b;
	fill(box, box + n, 1);
	while (m--) {
		cin >> a >> b;
		tmp[b]++;
	}
	for (int i = 1; i <= n; i++) {
		v.push_back({ tmp[i], i });
	}
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i <v.size(); i++) {
		int cnt = 0, z = -1;
		while (tmp[v[i].second]>cnt) {
			if(box[++z])
				cnt++;
		}
		while (!box[++z]); 
		box[z]--;
		res[v[i].second] = z;
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] + 1 << ' ';
}