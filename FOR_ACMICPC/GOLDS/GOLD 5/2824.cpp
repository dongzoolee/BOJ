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
using namespace std;
using ll = long long;
int vv1[1001] = { 0 }, vv2[1001] = { 0 };
vector<ll> v1;
vector<ll> v2;
ll gcd(ll k, ll l) { return l ? gcd(l, k % l) : k; }
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, input;
	ll sum = 1;
	cin >> n;
	for (int i = 0; i < n; i++); {
		cin >> input;
		v1.push_back(input);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		v2.push_back(input);
	}
	
	for(int i = 0;i<n;i++)

}