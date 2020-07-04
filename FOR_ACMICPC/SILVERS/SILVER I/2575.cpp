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
vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m;
	cin >> m;

	//A 

	

	//B 소인수분해
	int tmp = m;
	for (int i = 2; i <= tmp; i++) {
		int cnt = 0;
		while (tmp % i == 0){
			tmp /= i;
			cnt++;
			if (cnt == 1)
				v.push_back(i);
		}
	}

	cout << " " << v.size();

}