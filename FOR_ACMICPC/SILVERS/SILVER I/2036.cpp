	#include <iostream>
	#include <stdio.h>
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
	long long arr[100002], sum = 0;

	int main() {
		int n;
		cin >> n;
		int minus_i = -1;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);

		for (int i = 0; i < n; i++)
			if (arr[i] > 0) { // ������ - or 0���� ����. ���� ���� ����� -1�� �����.
				minus_i = i - 1;
				break;
			}
		if (arr[n - 1] <= 0) minus_i = n - 1;

		for (int i = 0; i <= minus_i; )
			if (i + 1 <= minus_i || (arr[i+1] == 0 && i+1<=minus_i)) { // -���� ¦��� ����, ���� �迭�� 0�̸� ������ ����
				sum += arr[i] * arr[i + 1];
				i += 2;
			} 
			else {
				sum += arr[i++]; // ¦�������� ������ �׳� ����
			}

		for (int i = n - 1; i > minus_i;) {
			if (i - 1 > minus_i && arr[i - 1] != 0 && arr[i - 1] != 1) { // + ���� ¦��� ����, 
				sum += arr[i] * arr[i - 1];
				i -= 2;
			}
			else {
				sum += arr[i--]; // �������� 0 �̰ų� 1�̸� �׳� ����.
			}
		}
		cout << sum;
	}
