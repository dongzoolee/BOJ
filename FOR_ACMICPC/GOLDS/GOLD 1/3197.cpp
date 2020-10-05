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
int arr[1500][1500];
vector<pair<int,int>>swan;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int f = 0; f < c; f++) {
			cin >> arr[i][f];	
			if (arr[i][f] == 'L')
				swan.push_back({ i,f });
		}

}