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
#include<set>
#include <numeric>
using namespace std;
using ll = long long;
set<int>s;
vector<int>v;
int m;
int maknum(int n) {
	int nlen = (int)log10(n) + 1, ret = 0;
	while (n) {
		ret += int(pow(n % 10, m));
		n /= 10;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n >> m;
	v.push_back(n);
	s.insert(n);
	while (1) {
		int next = maknum(n);
		if (s.find(next) == s.end()) {// ¾øÀ¸¸é
			s.insert(next);
			v.push_back(next);
			n = next;
		}
		else {
			cout << find(v.begin(), v.end(), next)-v.begin();
			break;
		}
	}
}