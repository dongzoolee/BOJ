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
	longs m = 1;	// 홀수 승에서 마지막에 남게되는 하나의 a 저장용도
	if (b == 0) return 1; // 지수가 0이면 1 return
	a %= c;	//	a는 그냥 c로 나눈 나머지로 세팅을 한다.
	while (b > 1) { // 지수가 1이 될 때까지
		if (b % 2 == 1)
			m = m * a % c; // 홀수 승에서 마지막에 남게되는 하나의 a
									   // 13^13 = 13^12 * 13
		a = a * a % c; // 모든 a^2n승의 나머지
		b /= 2;				// 짝수승은 모두 나머지가 a이므로 싹 2로 나눠버리기
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