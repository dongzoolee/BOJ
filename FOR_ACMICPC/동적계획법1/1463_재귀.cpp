#include <iostream>
#include <limits.h>
using namespace std;
int mini = INT_MAX;
// Ư�� ���ڿ� ���� �ּ� ���� Ƚ���� �������ִ� = ������ȹ��

void mid(int input, int counting) {
	if (mini < counting) // �� ������ ��¥ ũ��.......................
		return;			// �ּҸ� ���ϴ� �Ÿ� �߰��� ���ϴ°� ���� �߿� . . . . .. .

	while (input != 1) { // ���������� �������� 1�� �� ������ ��� ����
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
	mid(input, 0); // �˰��� ����

	cout << mini;
}

