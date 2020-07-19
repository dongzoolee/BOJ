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
//mst - �ּ� ���д� Ʈ��
// 1. ��� ���� connected
// 2. ���� ����ġ�� ���� �ּ�
// 3. ���� ���� : |V|-1
// w���� �������� ����
// cycle �� ���⵵�� w �����ź��� ����
// ���� ���� : |V|-1 �� ������
void init() {
	// 1. �ʱ�ȭ
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
	par[u] = v; // �ٲ� �� ����
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
	for (int i = 0; i < e; i++) { // ���� ����
		if (find(vec[i].second.first) == find(vec[i].second.second)) { // ������ ����?
			// ���� ���ٸ� 
			continue;
		}
		else { // ������ �޶�
			merge(vec[i].second.first, vec[i].second.second); // �׷� ���� Ʈ���� ����
			sum += vec[i].first; // sort�߱⶧��.
		}
		// ���� ���� ����......�����ϱ�........
	}
	cout << sum;
	return 0;
}