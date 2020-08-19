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
vector<int>v[20001];
int chk[20001];
bool chkr = 0;
// 2 == ����
// 0 == A��
// 1 == B��
void dfs(int idx, int bul) {
	for (int i = 0; i < v[idx].size(); i++) {
		if (chk[v[idx][i]] == 2) {
			// �� == bul
			// ���� �� == 1 - bul
			chk[v[idx][i]] = 1 - bul;
			dfs(v[idx][i], 1 - bul);
		}
		else if (chk[v[idx][i]] != 1 - bul) {
			// �ٵ� ���� ���� 1 - bul�� �ƴϰ� ���� ����?
			chkr = 1;
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc, a, b, c, d;
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		for (int f = 0; f < b; f++) {
			cin >> c >> d;
			v[c].push_back(d);
			v[d].push_back(c);
		}
		fill(chk, chk + 20001, 2);
		// ������� // dfs�� �������� Ž���������ʴ´�. ����������.
		for (int i = 1; i <= a; i++)
			if (chk[i] == 2) {
				chk[i] = 0;
				dfs(i, 0);
			}
		if (chkr)
			cout << "NO\n";
		else
			cout << "YES\n";
		chkr = 0;
		for (int i = 0; i < 20001; i++)
			v[i].clear();
	}
}