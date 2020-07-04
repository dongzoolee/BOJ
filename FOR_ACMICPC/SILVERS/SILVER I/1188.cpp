#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <limits.h>
using namespace std;
int counter = 0, extra = 1;
void nM(int n, int M);

void Nm(int N, int m) {
	if (N % m == 0) {	// check ?? 
		cout << counter;
		return;
	}

	if (N % m > m)
		Nm(N % m, m);
	else
		nM(N % m, m);
}

void nM(int n, int M) {
	if (n == 1) {
		counter += (M - 1) * extra;	//�Ʒ��� �ּ��� ���⼭ ó���Ѵ�.
		cout << counter;
		return;
	}
	if (M % n == 0) {
		extra = n;		// M�� n���� ������ �������� (1, M/n)�� �� ���ϱ� ���� ������ ����ص� ��������.
		nM(1, M / n);
	}
	else if (M - n < n) {
		counter += n;	// �̸�  n������ ��
		Nm(n, M - n);
	}
	else if (M - n > n) {	
		counter += n;					// �̸�  n������ ��
		counter += (M - n) / n * n;		// ������ �ֵ����� �ڸ��� ���� ����� �� �� ���� ������ �ڸ���.
		if (n < M - ((M - n) / n * n + n))
			nM(n, M - ((M - n) / n * n + n));
		else if (n > M - ((M - n) / n * n + n))
			Nm(n, M - ((M - n) / n * n + n));
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	if (N > M)
		Nm(N, M);
	else if (N < M)
		nM(N, M);
	else
		cout << "0";
}