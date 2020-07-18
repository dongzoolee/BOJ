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
#include <ctime>
#include <tuple>
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
vector<int> par(1000001, 0);
int n, m;
// disjoint //
void init() {
	// 1. 초기화
	for (int i = 0; i <= n; i++)
		par[i] = i;
}
int find(int u) {
	if (u == par[u]) return u;

	return par[u] = find(par[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);

	if (u == v) return;
	par[u] = v;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


}

//mst - 최소 스패닝 트리
// 1. 모든 정점 connected
// 2. 간선 가중치의 합이 최소
// 3. 간선 개수 : |V|-1
// w기준 오름차순 정렬
// cycle 안 생기도록 w 작은거부터 선택
// 간선 개수 : |V|-1 될 때까지