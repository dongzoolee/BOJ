#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;
int arr[51], loc[1000001];
int sun[51];
deque<int>v;
int cnt = 0, n;
bool chk[51] = { 0 };
void print() {
	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
	exit(0);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int s;
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> arr[i]; loc[arr[i]] = i; }
	v.push_back(-1);
	for (int h = 1000000; h > 0; h--) if (loc[h]) { v.push_back(loc[h]); sun[loc[h]] = v.size() - 1; }
	cin >> s;
	int og = s;
	for (int j = 1; j <= n; j++)
		for (int h = 1; h < v.size(); h++)
			if (chk[h] == 0 && sun[v[h]] < sun[j] && v[h] - j>0 && v[h] - j <= s) {
				chk[h] = 1;
				s -= v[h] - j;
				int len = v[h];
				for (int i = len; i > j; i--) {
					if (og > cnt) {
						cnt++;
						swap(arr[i], arr[i - 1]);
						swap(sun[i], sun[i - 1]);
						swap(v[sun[i]], v[sun[i - 1]]);
					}
					if (cnt == og) print();
				}
				break;
			}
	print();
	return 0;
}