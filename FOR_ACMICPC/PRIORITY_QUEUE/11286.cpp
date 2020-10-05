#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a;
	while (n--) {
		cin >> a;
		if (a)
			q.push({ abs(a),a });
		else
			if (q.empty())
				cout << 0 << '\n';
			else {
				cout << q.top().second << '\n';
				q.pop();
			}
	}
}