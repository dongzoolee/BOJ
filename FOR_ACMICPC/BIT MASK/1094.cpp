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
vector<int>v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int i = 0;
	for (i = 0; n >= int(pow(2, i)); i++);
	i--;
	while (n) {
		if (n >= (int)pow(2, i)) {
			n -= (int)pow(2, i);
			v.push_back(1);
		}
		else {
			v.push_back(0);
		}
		i--;
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i] == 1)
			cnt++;
	cout << cnt;
}