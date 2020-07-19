#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
int t, arr[4];
int gcd(int k, int l) { return l ? gcd(l, k%l) : k; }
int lcm(int k, int l) { return k / gcd(k, l)*l; }

void judge() {
	int llcm = lcm(arr[0], arr[1]);

	for (int i = 0;; i++) {
		if ((arr[0] * i + arr[2] - arr[3]) % arr[1] == 0) {
			cout << (arr[0] * i + arr[2]) << "\n";
			return;
		}
		if (llcm < arr[0] * i + arr[2]) {
			cout << "-1\n";
			return;
		}
	}
}

int main() {
	cin >> t;
	for (int f = 0; f < t; f++) {
		for (int i = 0; i < 4; i++)
			cin >> arr[i];
			judge();
	}

	return 0;
}