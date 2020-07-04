// BOJ

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <tuple>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Psi pair<string, int>
#define Tii tuple<int, int, int

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		string str;
		vector<char> vc;
		int l;
		bool flag = true;

		cin >> str;
		l = str.size();

		for (int j = 0; j < l; ++j) {
			if (str[j] == '(') vc.push_back('(');
			else {
				if (vc.empty()) {
					flag = false;
					break;
				}
				else vc.pop_back();
			}
		}
		if (!vc.empty()) flag = false;

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}