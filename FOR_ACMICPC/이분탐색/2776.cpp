#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tc;
	cin >> tc;
	int n, m;
	int a;
	while (tc--) {
		// 테케 많으면 초기화 해주라...
		vector<int>og;
		vector<int>test;

		cin >> n;
		while (n--) {
			cin >> a;
			og.push_back(a);
		}
		sort(og.begin(), og.end());
		cin >> m;
		while (m--) {
			cin >> a;
			int res = binary_search(og.begin(), og.end(), a);
			if (res)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}