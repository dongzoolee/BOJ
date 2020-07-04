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
	int arr[5002] = { 0 }, N, K, num_th = 3, temp, counter = 0, i = 1;
	cin >> N >> K;
	cout << "<";
	for (i; i <= N;) { // Á¶»ç¿ë for
		int sum = 0;
		while (sum < K) {
			if (arr[i++] == 0) {
				sum++;
				temp = i - 1;
			}
			if (i == N + 1)
				i = 1;
		}
		if (i == N + 1)
			i = 1;

		cout << temp;
		counter++;

		if (counter != N)
			cout << ", ";
		else
			cout << ">";

		arr[temp] = 1;
		if (counter == N)
			break;
	}
}