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
int arr[1000001] = { 0 };
vector <int> prime;
// 모든 수는 소인수분해가 가능하다.
// 모든 수의 소인수분해한 인수는 소수로 이루어져있다.
// 그러므로 2~1000000까지 소수를 input 값으로 나눠보고
// 나누어떨어지지 않는다면,
// 모든 (소인수분해한) 인수는 1000001 이상인 소수임이 보장된다.

void is_prime() {
	for (int i = 2; i < 1000001; i++)
		for (int f = i + i; f < 1000001; f += i)
			arr[f] = 1;
	int f = 0;
	for (int i = 2; i < 1000001; i++)
		if (arr[i] == 0)
			prime.push_back(i);
}

int main() {
	int tc;
	long long input;
	cin >> tc;
	is_prime();

	for (int i = 0; i < tc; i++) {
		bool just = 0;
		cin >> input;
		// 소인수분해
		for (int i = 0; i < prime.size(); i++) {
			if (input % prime[i] == 0) {
				just = 1;
				break;
			}
		}
		if (just)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}