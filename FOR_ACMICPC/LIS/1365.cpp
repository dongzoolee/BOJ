#include <iostream>
#include<vector>
using namespace std;
using ll = long long;
vector<int>v;
int main() {
	int n;
	cin >> n;
	int a;
	v.push_back(0);
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (v.back() < cur) {
			v.push_back(cur);
		}
		else *lower_bound(v.begin(), v.end(), cur) = cur;
	}
	cout << n - v.size()+1;
}