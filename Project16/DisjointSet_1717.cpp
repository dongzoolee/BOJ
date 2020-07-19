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
	// 1. 초기화
	for (int i = 0; i <= n; i++)
		parent[i] = i;
}

// 3. Find (찾기) 연산
// u 가 속한 트리의 루트 노드 번호를 반환한다.
int find(int u) {

	// 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
	if (u == parent[u]) return u;

	// 각 노드의 부모 노드를 찾아 올라간다.
	// 효율적인 .. 방법임↓↓↓
	return parent[u] = find(parent[u]);
}

// 2. Union (합치기) 연산
// u 가 속한 트리와 v 가 속한 트리를 합친다.
void merge(int u, int v) {

	// 각 원소가 속한 트리의 루트 노드를 찾는다.
	u = find(u); v = find(v);

	// u 와 v 가 이미 같은 트리에 속하는 경우에는 합치지 않는다.
	if (u == v) return;
	// else 합치기
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