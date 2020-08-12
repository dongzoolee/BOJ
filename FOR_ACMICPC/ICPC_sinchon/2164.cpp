#include <iostream>
#include<queue>
#include<vector>
#include<deque>
using namespace std;
using ll = long long;
deque<int>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	v.resize(n * 2);
	for (int i = 1; i <= n; i++) v[i-1] = i;
	int frt = 0, bk = n-1;
	while (1) {
		if (frt == bk) {
			cout << v[frt];
			break;
		}
		else {
			frt++;
			v[++bk] = v[frt++];
		}
	}
}