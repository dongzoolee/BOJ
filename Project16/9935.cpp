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
#include <ctime>
using namespace std;
using ll = long long;
bool chk[123] = { 0 }, bol = 0;

// ������ ������ �����غ���.
// �׷��� vec.erase �Ⱦ��� �˾Ƽ� ��ġ�� �Ű����ϱ�.
// merge�� ���ѹ����� �ݺ��ؾ��� �� ������ ����Ѵ�.
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str, bomb;
	cin >> str >> bomb;
	for (int i = 0; i < bomb.length(); i++)
		chk[bomb[i]]= 1;

	for (int i = 0; i < str.length(); i++)
		if (chk[str[i]] == 0) {
			cout << str[i];
			bol = 1;
		}
	if (bol == 0)
		cout << "FRULA";
}