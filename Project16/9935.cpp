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

// 스택인 이유를 생각해보자.
// 그래야 vec.erase 안쓰고도 알아서 위치가 옮겨지니까.
// merge를 무한번으로 반복해야할 때 스택을 사용한다.
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