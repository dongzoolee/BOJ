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
vector<int>v[500001];
int chk[500001];
vector<int>leaf;
void dfs(int idx) {
	int cnt = 0;

	for (int i = 0; i < v[idx].size(); i++) {
		if (chk[v[idx][i]]) continue;

		chk[v[idx][i]] = 1;
		cnt++;
		dfs(v[idx][i]);
	}
	if (cnt == 0) {
		leaf.push_back(idx);
	}
}
int main() {
	int n;
	double w;
	scanf("%d %lf", &n, &w);
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	chk[1] = 1;
	dfs(1);
	double ans = w / leaf.size();
	printf("%.10lf", ans);
}
