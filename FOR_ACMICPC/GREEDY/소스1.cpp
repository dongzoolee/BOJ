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
	for (int i = 1; i <= 50; i++)
		v.push_back(i);
	
	for(int i = 0;i<1000000;i++)
		next_permutation(v.begin(), v.end());
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 50; i++) cout << v[i] << ' ';
}