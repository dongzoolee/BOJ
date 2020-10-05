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
int inDegree[32001];
vector<int>v[32001];
priority_queue<int, vector<int>, greater<int>>q;
vector<int>rem[32001];
void judge(int num) {
	q.pop();

	for (int i = 0; i < v[num].size(); i++) {
		int y = v[num][i];
		if (--inDegree[y] == 0)
			q.push(y);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b;
	while (m--) {
		cin >> a >> b;
		inDegree[b]++;
		v[a].push_back(b);
	}
	int q_max;
	for (int i = 1; i <= n; i++) {
		if(inDegree[i] == 0)
			q.push(i);
		else {
			rem[inDegree[i]].push_back(i);
		}
	}
	q_max = *max_element(inDegree, inDegree + 32001);
	while (q.size()) {
		cout << q.top() << ' ';
		judge(q.top());
	}
}