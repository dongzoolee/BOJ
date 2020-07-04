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
int arr[1001][3], dp[1001][3];

int main() {
	int houses;
	cin >> houses;

	for (int i = 0; i < houses; i++)
		for (int f = 0; f < 3; f++)
			cin >> arr[i][f];

	dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];
	for (int i = 1; i < houses; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	int temp = min(dp[houses - 1][0], dp[houses - 1][1]);
	temp = min(dp[houses - 1][2], temp);
	cout << temp;
}