#include <iostream>
#include <limits.h>
using namespace std;
int mini = INT_MAX;
// 특정 숫자에 대한 최소 연산 횟수가 정해져있다 = 동적계획법

void mid(int input, int counting) {
	if (mini < counting) // 이 한줄이 진짜 크다.......................
		return;			// 최소를 구하는 거면 중간에 컷하는게 정말 중요 . . . . .. .

	while (input != 1) { // 최종적으로 나눈값이 1이 될 때까지 계속 돌림
		if (input % 2 == 0) {
			mid(input / 2, counting + 1);
		}
		if (input % 3 == 0) {
			mid(input / 3, counting + 1);
		}
			mid(input - 1, counting + 1);
			return;
	}
	if (counting < mini)
		mini = counting;
}

int main(void) {
	int input;

	cin >> input;
	if (input == 1) {
		cout << "0";
		return 0;
	}
	mid(input, 0); // 알고리즘 시작

	cout << mini;
}

