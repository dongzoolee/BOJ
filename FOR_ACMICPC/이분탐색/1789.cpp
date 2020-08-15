#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll s;
	cin >> s;
	/*int start = 1;
	int end = s;
	int mid = (start + end) / 2;
	while (start <= end) {
		mid = (start + end) / 2;
		int sum = 0;


	}*/
	ll sum = 0;
	ll i;
	for (i = 1; sum + i <= s; i++) {
		sum += i;
	}
	cout << i - 1;
}