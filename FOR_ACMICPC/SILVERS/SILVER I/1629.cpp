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
using longs = long long;
long long counter = 0;

longs moding(longs a, longs b, longs c) {
	longs m = 1;	// Ȧ�� �¿��� �������� ���ԵǴ� �ϳ��� a ����뵵
	if (b == 0) return 1; // ������ 0�̸� 1 return
	a %= c;	//	a�� �׳� c�� ���� �������� ������ �Ѵ�.
	while (b > 1) { // ������ 1�� �� ������
		if (b % 2 == 1)
			m = m * a % c; // Ȧ�� �¿��� �������� ���ԵǴ� �ϳ��� a
									   // 13^13 = 13^12 * 13
		a = a * a % c; // ��� a^2n���� ������
		b /= 2;				// ¦������ ��� �������� a�̹Ƿ� �� 2�� ����������
	}
	return a * m % c;
}

int main() {
	longs a, b, c;
	cin >> a >> b >> c;
	//long long mod_a = a % c - c, temp;
	//long long mod_a1 = a % c;
//	if ((long long)abs(mod_a) < mod_a1 && b != 1)
	//	temp = mod_a1;
//	else
	//	temp = mod_a;

	cout << moding(a, b, c);
}