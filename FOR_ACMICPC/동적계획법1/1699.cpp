#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
int dp[100001];

int main() {
	int n;
	cin >> n;
	int i = n, temp;
	dp[1] = 1;


	for (int f = 2; f <= n; f++) {	   // pow �ð� ���⵵�� �����. ���� ���� ����.
		int temp = (int)pow(f, 0.5);
		if (f != temp * temp) {	//	������ �ɷ�����
			for (int h = 1; h <= temp; h++)
				if (h == 1)
					dp[f] = dp[h * h] + dp[f - h * h];
				else
					dp[f] = min(dp[f], dp[h * h] + dp[f - h * h]);
		}
		else
			dp[f] = 1;
	}
	cout << dp[n];
}