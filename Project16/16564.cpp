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
vector<pair<int, int>>v;
int arr[1000000];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int cnt = 0, temp = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] == temp) {
			cnt++;
		}
		else {
			v.push_back({ arr[i - 1], cnt });
			cnt = 1;
		}
		temp = arr[i];
	}
	v.push_back({ arr[n - 1], cnt });

	int sz = v.size();
	for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end()-1;) {
		int tmp = ((it + 1)->first - it->first)*it->second;
		if (tmp < k) {
			k -= tmp;
			(it + 1)->second += it->second;
			it = v.erase(v.begin());
		}
		else {
			cout << it->first + k / it->second;
			break;
		}
	}
	/*
	for (int i = 1; i < sz; i++) {
		int tmp = (v[i].first - v[i - 1].first)*v[i-1].second;
		if (tmp < k) {
			k -= tmp;
			v[i].second += v[i - 1].second;
			v.erase(v.begin());
		}
		else {
			cout << v[i - 1].first + k / v[i-1].second;
			break;
		}
	}
	*/
}