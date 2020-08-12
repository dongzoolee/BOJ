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
int tenp[] = { 1,10,100,1000,10000,100000,1000000 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	string str, num;
	int n;
	while (tc--) {
		deque<int>v;
		deque<int>tmp;
		cin >> str >> n >> num;
		bool error = 0;
		int nlen = num.length();
		int idx = 1, temp = 0;
		for (int i = 1; i < nlen; i++) {
			if (num[i] == ']' || num[i] == ',') {
				temp = 0;
				for (int f = idx; f < i; f++)
					temp += (num[f] - '0') * tenp[i - f - 1];
				if (temp) v.push_back(temp);
				idx = i + 1;
			}
		}
		int slen = str.length();
		int frt = 0, bk = v.size() - 1;
		bool cur = 0;
		for (int i = 0; i < slen; i++) {
			if (str[i] == 'R') {
				cur = (1 - cur);
			}
			else {
				if (bk < frt) {
					cout << "error\n";
					error = 1;
					break;
				}
				else if (cur) {
					bk--;
				}
				else
					frt++;
			}
		}
		if (error) continue;
		else {
			cout << '[';
			if (cur)
				for (ll i = bk; i >= frt; i--) {
					cout << v[i];
					if (i != frt) cout << ',';
				}
			else
				for (ll i = frt; i <= bk; i++) {
					cout << v[i];
					if (i != bk) cout << ',';
				}
			cout << "]\n";
		}
	}
}