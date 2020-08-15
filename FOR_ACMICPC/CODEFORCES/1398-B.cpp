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
	while (tc--) {
		vector<int>v;
		cin >> str;
		int tmp = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '0') {
				if (tmp)
					v.push_back(tmp);
				tmp = 0;
			}
			else {
				tmp++;
			}
		}
		if (tmp)
			v.push_back(tmp);
		sort(v.begin(), v.end(), greater<>());
		int sum = 0;
		for (int i = 0; i < v.size(); i+=2) {
			sum += v[i];
		}
		cout << sum << '\n';
	}
}
