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
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int r, g, b, w;
void judge() {
	// r g b���� �ϳ��� �� ���?
	int sum = 0;
	if (r <= 0 || g <= 0 || b <= 0) { cout << "NO\n"; return; }
	if (r > 0) {
		sum += 1;
		r--;
	}
	if (g > 0) {
		sum += 1;
		g--;
	}
	if (b > 0) {
		sum += 1;
		b--;
	}
	w += sum;

	if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0 && w % 2 == 0) {
		cout << "YES\n";
		return;
	}
	else if (r % 2 && g % 2 == 0 && b % 2 == 0 && w % 2 == 0) {
		cout << "YES\n";
		return;
	}
	else if (r % 2 == 0 && g % 2 && b % 2 == 0 && w % 2 == 0) {
		cout << "YES\n";
		return;
	}
	else if (r % 2 == 0 && g % 2 == 0 && b % 2 && w % 2 == 0) {
		cout << "YES\n";
		return;
	}
	else if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0 && w % 2) {
		cout << "YES\n";
		return;
	}
	else {
		cout << "NO\n";
		return;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;

	while (tc--) {
		cin >> r >> g >> b >> w;
		// Ȧ�� �Ѱ�����? or all ¦��
		// w���� ��� ���� ���ÿ� ��ȯ�ؾ���;;
		// possibly zero
		if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		else if (r % 2 == 0 && g % 2 == 0 && b % 2 && w % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		else if (r % 2 == 0 && g % 2 && b % 2 == 0 && w % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		else if (r % 2 && g % 2 == 0 && b % 2 == 0 && w % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		else {
			judge();
		}
	}
}