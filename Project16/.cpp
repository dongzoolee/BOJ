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
vector<vector<int>>v;
vector<int>paring[1000001];
int arr[1000001] = { 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, a, b, c, z = 1;
	cin >> n >> m;
	v.push_back(vector<int>()); // v[0]는 garbage
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 0) {
			cin >> b >> c;
			if (arr[b] == 0 && arr[c] == 0) {
				v.push_back(vector<int>());
				v[z].push_back(b);
				v[z].push_back(c);
				arr[b] = z, arr[c] = z;
				z++;
			}
			else if (arr[b] == 0 && arr[c] != 0) {
				arr[b] = arr[c];
				v[arr[b]].push_back(b);
			}
			else if (arr[b] != 0 && arr[c] == 0) {
				arr[c] = arr[b];
				v[arr[c]].push_back(c);
			}
			else {
				paring[arr[b]].push_back(arr[c]);
				paring[arr[c]].push_back(arr[b]);
			}
		}
		else {
			cin >> b >> c;
			if (arr[b] == arr[c])
				cout << "yes\n";
			else if (find(paring[arr[b]].begin(), paring[arr[b]].end(), arr[c]) != paring[arr[b]].end()) {
				// 찾았다면
				cout << "yes\n";
			}
			else
				cout << "no\n";
		}
	}
	// unique
}