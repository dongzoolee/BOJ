#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int num[52], length, sum = 0, min = INT_MAX, temp;
	char ch[52];
	
	for (int i = 0; i < 51; i++) {
		if (i != 0) {
			scanf("%c", &ch[i]);
			if (ch[i] == '\n') { // \n �Է������� scan
				length = i; // ������ ���� - 1�� ��ȣ�� ������ ����.
				break;
			}
		}
		cin >> num[i];
	}

	sum += num[0];
	for (int i = 1; i < length; i++) // �ϴ� ���� ���� �� ���ϱ�
		if (ch[i] == '-')
			sum -= num[i];
		else
			sum += num[i];

	temp = sum;
	for (int i = 1; i < length; i++) { // ��ȣ ����
		if (ch[i] == '-') {
			for (int f = i + 1; f < length; f++) {
				if (ch[f] == '+')
					temp -= 2 * num[f];
			}
			break;
		}
	}

	cout << temp;
					
}