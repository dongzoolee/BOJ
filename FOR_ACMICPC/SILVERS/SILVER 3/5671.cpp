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

int main() {
	int N, M, length, counter;
	while (scanf("%d %d", &N, &M) != EOF) {
		counter = 0;
		for (int i = N; i <= M; i++) {
			int arr[11] = { 0 };
			int temp = i;
			for (int f = 0; f < (int)log10(i) + 1; f++)
				if (arr[temp % 10] == 0) {
					arr[temp % 10] = 1;
					temp /= 10;
				}
				else {
					counter++;
					break;
				}
		}
		cout << M - N - counter + 1 << "\n";
	}
}