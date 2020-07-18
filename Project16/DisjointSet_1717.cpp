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
#include <ctime>
using namespace std;
using ll = long long;
vector<int> parent(1000001, 0);
int n, m;
void init() {
	// 1. �ʱ�ȭ
	for (int i = 0; i <= n; i++)
		parent[i] = i;
}

// 3. Find (ã��) ����
// u �� ���� Ʈ���� ��Ʈ ��� ��ȣ�� ��ȯ�Ѵ�.
int find(int u) {

	// ��Ʈ ���� �θ� ��� ��ȣ�� �ڱ� �ڽ��� ������.
	if (u == parent[u]) return u;

	// �� ����� �θ� ��带 ã�� �ö󰣴�.
	// ȿ������ .. ����ӡ���
	return parent[u] = find(parent[u]);
}

// 2. Union (��ġ��) ����
// u �� ���� Ʈ���� v �� ���� Ʈ���� ��ģ��.
void merge(int u, int v) {

	// �� ���Ұ� ���� Ʈ���� ��Ʈ ��带 ã�´�.
	u = find(u); v = find(v);

	// u �� v �� �̹� ���� Ʈ���� ���ϴ� ��쿡�� ��ġ�� �ʴ´�.
	if (u == v) return;
	// else ��ġ��
	parent[u] = v;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	init();

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a;
		cin >> b >> c;
		if (a == 0) {
			merge(b, c);
		}
		else {
			int b_parent = find(b);
			int c_parent = find(c);

			if (b_parent == c_parent)
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}
	return 0;
}