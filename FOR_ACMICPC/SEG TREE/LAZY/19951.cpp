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
	//구간 [ns,ne) node의 lazy 값을 propagate
	void propagate(int node, int ns, int ne) {
		// lazy 값이 존재하면 실행
		if (lazy[node] != 0) {
			// 리프 노드가 아니라면 자식들에게 lazy 미룸
			if (node < base) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			// 자신에 해당하는 만큼의 값을 더함
			seg[node] += lazy[node] * (ne - ns);
			// 다 쓴 lazy 초기화
			lazy[node] = 0;
		}
	}

	void add(int s, int e, int k) { add(s, e, k, 1, 0, base); }
	void add(int s, int e, int k, int node, int ns, int ne) {
		// 일단 propagate
		propagate(node, ns, ne);

		// 범위가 불량하면 return;
		if (e <= ns || ne <= s) return;
		// 완전히 포함될 때만 진행
		if (s <= ns && ne <= e) {
			// lazy 부여 후, propagate
			lazy[node] += k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns + ne) / 2;
		add(s, e, k, node * 2, ns, mid);
		add(s, e, k, node * 2 + 1, mid, ne);
		// 마지막에 자식들의 값을 사용하여 
		// 다시 자신의 값을 갱신
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
	int sum(int s, int e) { return sum(s, e, 1, 0, base); }
	int sum(int s, int e, int node, int ns, int ne) {
		// 남아있는 lazy들 다 처리해주기
		propagate(node, ns, ne);

		// 범위 밖이면 관심이 없다.
		if (e <= ns || ne <= s) return 0;
		// ns ne를 포함하면 바로 값 return
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