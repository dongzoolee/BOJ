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
long long counter = 0;
long long A, B;
int arr[10000001] = { 0 };
vector<int> vec;
void is_prime(int num) {
	for (long long i = 2; i < 10000001; i++)
		for (long long f = i + i; f < 10000001; f += i)
			arr[f] = 1;

	for (int i = 2; i <= 10000000; i++)
		if (arr[i] == 0)
			vec.push_back(i);
}

int main() {
	cin >> A >> B;
	is_prime(1);	// 1���� sqrt(10^14)������ �Ҽ��� ���մϴ�.
	double one = A, two = B;

	for (int i = 0; i < vec.size() && vec[i] <= B; i++) {
		double n = log(one) / log(vec[i]); // ���� ������ �� ������ �Ҽ��� �� ������ ���մϴ�.
		if (n - (int)n != 0)
			n += 1;	// ���� �Ҽ��� �������� A�� ��ġ�Ѵٸ� �׳� pass
					// ���� ��ġ���� �ʴ´ٸ�, +1 ���ݴϴ�.
					// ex) log2 13 == 3.xxx , 2^3�� 13���� �����Ƿ� 2^4���� �����ؾ��մϴ� 
		double m = log(two) / log(vec[i]);
		if (n < 2)
			n = 2;	// �츰 �Ҽ���^N, N>=2�� ���� ���ϴ� ���Դϴ�.
		for (int f = (int)n; f <= (int)m; f++) // �Ҽ� ���̱� ������ �������� �����ֱ����� int ����ȯ�� �մϴ�.
			counter++;
	}

	cout << counter;
}