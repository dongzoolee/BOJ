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
int n;
struct seg {
	int base;
	vector<int>seg;
	vector<int>lazy;
	//���� [ns,ne) node�� lazy ���� propagate
	void propagate(int node, int ns, int ne) {
		// lazy ���� �����ϸ� ����
		if (lazy[node] != 0) {
			// ���� ��尡 �ƴ϶�� �ڽĵ鿡�� lazy �̷�
			if (node < base) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			// �ڽſ� �ش��ϴ� ��ŭ�� ���� ����
			seg[node] += lazy[node] * (ne - ns);
			// �� �� lazy �ʱ�ȭ
			lazy[node] = 0;
		}
	}

	void add(int s, int e, int k) { add(s, e, k, 1, 0, base); }
	void add(int s, int e, int k, int node, int ns, int ne) {
		// �ϴ� propagate
		propagate(node, ns, ne);

		// ������ �ҷ��ϸ� return;
		if (e <= ns || ne <= s) return;
		// ������ ���Ե� ���� ����
		if (s <= ns && ne <= e) {
			// lazy �ο� ��, propagate
			lazy[node] += k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns + ne) / 2;
		add(s, e, k, node * 2, ns, mid);
		add(s, e, k, node * 2 + 1, mid, ne);
		// �������� �ڽĵ��� ���� ����Ͽ� 
		// �ٽ� �ڽ��� ���� ����
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
	int sum(int s, int e) { return sum(s, e, 1, 0, base); }
	int sum(int s, int e, int node, int ns, int ne) {
		// �����ִ� lazy�� �� ó�����ֱ�
		propagate(node, ns, ne);

		// ���� ���̸� ������ ����.
		if (e <= ns || ne <= s) return 0;
		// ns ne�� �����ϸ� �ٷ� �� return
		if (s <= ns && ne <= e) return seg[node];
		int mid = (ns + ne) / 2;
		return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid, ne);
	}
	int to_propagate(int node, int l, int r) {
		if (node >= base) return 0;
		propagate(node, l, r);
		int mid = (l + r) / 2;
		return to_propagate(node * 2, l, mid) + to_propagate(node * 2 + 1, mid, r);
	}
	void init() {
		for (base = 1; base < n; base *= 2);
		seg.resize(base * 2);
		lazy.resize(base * 2);
		fill(lazy.begin(), lazy.end(), 0);
		for (int i = base; i < base + n; i++)
			cin >> seg[i];
		for (int i = base - 1; i > 0; i--)
			seg[i] = seg[2 * i] + seg[2 * i + 1];
	}
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	seg st;
	int m;
	cin >> n >> m;
	st.init();
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		st.add(a - 1, b, c);
	}
	st.to_propagate(1, 0, st.base);
	/*for (int i = 0; i < st.lazy.size(); i++)
		cout << st.lazy[i] << ' ';
	cout << '\n';*/
	for (int i = st.base; i < st.base + n; i++) {
		cout << st.seg[i] + st.lazy[i] << ' ';
	}
}