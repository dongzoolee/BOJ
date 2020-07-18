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
	// 1. �ʱ�ȭ
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

//mst - �ּ� ���д� Ʈ��
// 1. ��� ���� connected
// 2. ���� ����ġ�� ���� �ּ�
// 3. ���� ���� : |V|-1
// w���� �������� ����
// cycle �� ���⵵�� w �����ź��� ����
// ���� ���� : |V|-1 �� ������