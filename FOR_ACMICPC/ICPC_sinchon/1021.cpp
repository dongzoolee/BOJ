#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
vector<int>v;
int location[101], arr[101];
int cnt = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, a;
	cin >> n >> m;
	v.resize(n * 3);
	for (int i = 0; i < m; i++) { cin >> arr[i]; }
	// ���ڵ��� idx�� ����
	for (int i = 1; i <= n; i++) location[i] = i + n - 1;
	// ���ʿ� ������ �� �����Ƿ� �߰����� ����
	for (int f = n; f < 2 * n; f++)
		v[f] = f - n + 1;

	int frt = n, bk = 2 * n - 1;
	for (int i = 0; i < m; i++) {
		int x = location[arr[i]] - frt; // ���ʺ��� arr[i]������ �Ÿ�
		int y = bk - location[arr[i]] + 1; // �����ʺ��� arr[i]������ �Ÿ�
		if (x < y) {
			cnt += x;
			while (x--) { location[v[frt]] = ++bk; v[bk] = v[frt++]; }
			frt++;
		}
		else {
			cnt += y;
			while (y--) { location[v[bk]] = --frt; v[frt] = v[bk--]; }
			frt++;
		}
	}
	cout << cnt;
}