#include <iostream>
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
using ll = long long;
string str1, str2;
int arr[1001][1001] = { 0 }, st1len, st2len;
void lcs() {
	for (int i = 1; i <= st1len; i++)
		for (int f = 1; f <= st2len; f++) {
			if (str2[f - 1] == str1[i - 1]) // �߿�! ������ 0���� ���ϴ� ������ ���ڿ��� (0, 0)���� ��ġ�� ����	
				arr[i][f] = arr[i - 1][f - 1] + 1;
			else
				arr[i][f] = max(arr[i][f - 1], arr[i - 1][f]);
		}

	cout << arr[st1len][st2len];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str1 >> str2;
	st1len = str1.length(), st2len = str2.length();
	lcs();
}