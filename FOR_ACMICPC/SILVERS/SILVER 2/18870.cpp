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
using longs = long long;
vector <longs> v;
vector <longs> v_og;

int main() {
	longs input;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
		v_og.push_back(input);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n;i++) {
		cout << lower_bound(v.begin(), v.end(), v_og[i]) - v.begin() << " ";
}