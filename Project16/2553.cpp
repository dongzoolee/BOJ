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
ll sum = 1;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	
	for (int i = 1; i <= n; i++) {
		ll temp = sum * i;
		for(int i = 0;i<(ll)log10(temp)+1;i++)
			if (temp % 10 == 0)
				temp /= 10;
			else


	}
}