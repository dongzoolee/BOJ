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
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
priority_queue<int>q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { 
		int a;
		cin >> a;
		if (q.empty() && a == 0) cout << 0 << "\n";
		else if (a == 0) { cout << q.top() << "\n"; q.pop(); }
		else q.push(a);
	}
}