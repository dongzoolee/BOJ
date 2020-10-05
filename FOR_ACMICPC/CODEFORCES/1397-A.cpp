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
	string str;
	int n;
	while (tc--) {
		cin >> n;
		int ch[26] = { 0 };
		for (int f = 0; f < n; f++) {
			cin >> str;
			for (int i = 0; i < str.length(); i++)
				ch[str[i] - 'a']++;
		}
		bool no = 0;
		for (int i = 0; i < 26; i++)
			if (ch[i] % n)
				no = 1;
		if (no)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}