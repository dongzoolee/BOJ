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
	is_prime(1);	// 1부터 sqrt(10^14)까지의 소수를 구합니다.
	double one = A, two = B;

	for (int i = 0; i < vec.size() && vec[i] <= B; i++) {
		double n = log(one) / log(vec[i]); // 시작 범위와 끝 범위가 소수의 몇 승인지 구합니다.
		if (n - (int)n != 0)
			n += 1;	// 만약 소수의 제곱수가 A와 일치한다면 그냥 pass
					// 만약 일치하지 않는다면, +1 해줍니다.
					// ex) log2 13 == 3.xxx , 2^3은 13보다 작으므로 2^4부터 시작해야합니다 
		double m = log(two) / log(vec[i]);
		if (n < 2)
			n = 2;	// 우린 소수의^N, N>=2의 값만 구하는 중입니다.
		for (int f = (int)n; f <= (int)m; f++) // 소수 꼴이기 때문에 나머지를 없에주기위해 int 형변환을 합니다.
			counter++;
	}

	cout << counter;
}