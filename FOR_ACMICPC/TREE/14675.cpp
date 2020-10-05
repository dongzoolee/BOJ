#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
vector<int>v[100001];
int n, m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> m;
	while(m--){
		cin >> a >> b;
		if (a == 1) { // 단절점
			if (v[b].size() >= 2)
				cout << "yes\n";
			else
				cout << "no\n";
		}
		else { // 단절선
			cout << "yes\n";
		}
	}
}