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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	int a;
	string str;
	while (tc--) {
		cin >> a >> str;
		for (int f = 0; f < a; f++) {
			bool zchk = 0, ochk = 0;
			for (int i = 0; i < a; i++) {
				if (str[i + f] == '0')
					zchk = 1;
				else
					ochk = 1;
				if (zchk && ochk) break;
			}
			if (zchk && ochk) cout << 0;
			else if (zchk) {
				if (f == 0) {
					for (int i = 0; i < a; i++)
						cout << 0;
					break;
				}
				cout << 0; 
			}
			else { 
				if (f == 0) {
					for (int i = 0; i < a; i++)
						cout << 1;
					break;
				}
				cout << 1; 
			}
		}
		cout << '\n';
	}
}