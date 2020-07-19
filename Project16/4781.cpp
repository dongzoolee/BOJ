//호텔문제랑 똑같음. 뭔지 모르겠음

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
double n, balance, candy[5000][2];
int calories;

void calculate() {

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> n >> balance;
		if (n == 0 && balance == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> candy[i][0] >> candy[i][1];
		}
		calculate();
		cout << calories << '\n';
	}
}