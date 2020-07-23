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
vector<int> par(10001, 0);
vector<pair<int, pair<int, int>>>vec;
int v, e, sum = 0;
// disjoint //
//mst - 최소 스패닝 트리
// 1. 모든 정점 connected
// 2. 간선 가중치의 합이 최소
// 3. 간선 개수 : |V|-1
// w기준 오름차순 정렬
// cycle 안 생기도록 w 작은거부터 선택
// 간선 개수 : |V|-1 될 때까지
void init() {
	// 1. 초기화
	for (int i = 0; i <= v; i++)
		par[i] = i;
}
int find(int u) {
	if (u == par[u]) return u;

	return par[u] = find(par[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);

	if (u == v) return;
	par[u] = v; // 바뀔 수 있음
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}
	sort(vec.begin(), vec.end());
	init();
	for (int i = 0; i < e; i++) { // 간선 돌기
		if (find(vec[i].second.first) == find(vec[i].second.second)) { // 엄마가 같니?
			// 만약 같다면 
			continue;
		}
		else { // 엄마가 달라
			merge(vec[i].second.first, vec[i].second.second); // 그럼 같은 트리로 연결
			sum += vec[i].first; // sort했기때문.
		}
		// 간선 갯수 세기......구현하기........
	}
	cout << sum;
	return 0;
}