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
		counter += (M - 1) * extra;	//아래의 주석을 여기서 처리한다.
		cout << counter;
		return;
	}
	if (M % n == 0) {
		extra = n;		// M이 n으로 나누어 떨어지면 (1, M/n)의 값 곱하기 나눈 값으로 계산해도 문제없다.
		nM(1, M / n);
	}
	else if (M - n < n) {
		counter += n;	// 미리  n명한테 줌
		Nm(n, M - n);
	}
	else if (M - n > n) {	
		counter += n;					// 미리  n명한테 줌
		counter += (M - n) / n * n;		// 나머지 애들한테 자르지 않은 덩어리로 줄 수 있을 때까지 자른다.
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