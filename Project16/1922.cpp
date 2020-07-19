#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <ctime>
using namespace std;
using ll = long long;
vector<pair<int, int>>v[1001];

void dijk() {

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, inp1, inp2;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> inp1 >> inp2;
		v[i].push_back({ inp2,inp1 }); // 항상주의! pq쓰기위해 가중치가 first
	}

	dijk();
}