#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <ctime>
using namespace std;
using ll = long long;
int n;
bool is_prime[5000001] = { 0 };
vector<int>v;
void era() {
	is_prime[1] = 1; // ¼Ò¼ö x
	for (int i = 2; i <= 2239; i++)
		if (is_prime[i] == 0) {
			v.push_back(i); // 
			for (int f = i + i; f <= 2239; f += i)
				is_prime[f] = 1;
		}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	era();
	int sz = v.size();
	while (tc--) {
		cin >> n;
		for (int i = 0; i < sz; i++) {
			if (n == 0) break;

			while (n % v[i] == 0) {
				n /= v[i];
				cout << v[i] << ' ';
			}
		}
		if (n != 1) cout << n << " ";
		cout << '\n';
	}
}