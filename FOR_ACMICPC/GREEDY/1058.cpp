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
int sum[50];
int chk[50][50];
vector<int>v[50];

void cal(int idx) {
	for (int i = 0; i < v[idx].size() - 1; i++)
		for (int f = i + 1; f < v[idx].size(); f++) {
			if (chk[v[idx][i]][v[idx][f]]) continue;

			sum[v[idx][i]]++;
			sum[v[idx][f]]++;
			chk[v[idx][i]][v[idx][f]] = 1;
		}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string str;
	for (int f = 0; f < n; f++) {
		cin >> str;
		for (int i = f; i < n; i++)
			if (str[i] == 'Y') {
				v[f].push_back(i);
				v[i].push_back(f);
				if (chk[f][i] == 0) {
					chk[f][i] = 1;
					sum[f]++;
					sum[i]++;
				}
			}
	}
	for (int i = 0; i < n; i++) if(v[i].size()) cal(i);
	cout << *max_element(sum, sum + 50);
}