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
// ��� ���� ���μ����ذ� �����ϴ�.
// ��� ���� ���μ������� �μ��� �Ҽ��� �̷�����ִ�.
// �׷��Ƿ� 2~1000000���� �Ҽ��� input ������ ��������
// ����������� �ʴ´ٸ�,
// ��� (���μ�������) �μ��� 1000001 �̻��� �Ҽ����� ����ȴ�.

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
		// ���μ�����
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