#include<iostream>
using namespace std;
int date[3][4];
long sum = 0;

bool y_p(int year) {
	if ((year % 4 == 0 && year % 100 !=0) || year%400 ==0) {
		//����
		return 1;
	}
	else{
		//���
		return 0;
	}
}
void duplication(int tmp,int year) {
	if (y_p(year) == 1) {
		if (tmp == 2)
			sum += 29;
		else if (tmp == 4 || tmp == 6 || tmp == 9 || tmp == 11)
			sum += 30;
		else
			sum += 31;
	}
	else {
		if (tmp == 2)
			sum += 28;
		else if (tmp == 4 || tmp == 6 || tmp == 9 || tmp == 11)
			sum += 30;
		else
			sum += 31;
	}
}

void remaining_mid() {
	int temp;
	if (date[0][0] != date[1][0]) {
		temp = date[0][1] + 1;
		while (temp < 13) {
			duplication(temp, date[0][0]);
			temp++;
		}

		temp = date[1][1] - 1;
		while (temp > 0) {
			duplication(temp, date[1][0]);
			temp--;
		}
	}
	else { // 
		temp = date[1][1] - 1;
		while (temp != date[0][1]) {
			duplication(temp, date[0][0]);
			temp--;
		}
	}
}

void startend() {
	if (!(date[0][0] == date[1][0] && date[0][1] == date[1][1])) {
		//���۴�
		if (y_p(date[0][0]) == 1) { // ������ ���
			if (date[0][1] == 2)
				sum += (29 - date[0][2]);
			else if (date[0][1] == 4 || date[0][1] == 6 || date[0][1] == 9 || date[0][1] == 11)
				sum += (30 - date[0][2]);
			else
				sum += (31 - date[0][2]);
		}
		else {						// ����� ���
			if (date[0][1] == 2)
				sum += (28 - date[0][2]);
			else if (date[0][1] == 4 || date[0][1] == 6 || date[0][1] == 9 || date[0][1] == 11)
				sum += (30 - date[0][2]);
			else
				sum += (31 - date[0][2]);
		}
		//D-DAY
		sum += date[1][2];
		remaining_mid();
	}
	else { // ������ ������ ���� �������
		sum = date[1][2] - date[0][2];
		return;
	}
}

void mid() {
	int temp = date[0][0] + 1;
	while (temp < date[1][0]) { // �� ���� ���̿� �� ��(��)���� count (ó��, �� ����)
		if ((temp % 4 == 0 && temp % 100 != 0) || temp % 400 == 0) {
			//����
			sum += 366;
		}
		else {
			//���
			sum += 365;
		}

		temp++;
	}
	startend(); // ó��, �� ����Ϸ�����
}

int main() {
	for (int i = 0; i < 2; i++)
		for (int f = 0; f < 3; f++)
			cin >> date[i][f];

	if ((date[1][0] - date[0][0] == 1000 && (date[1][1]>date[0][1] || (date[1][1]==date[0][1] && date[1][2]>=date[0][2]))) || date[1][0] - date[0][0] > 1000) {
		cout << "gg"; //��¥ �񶧸���..... 1000�� �̻��� �Ǵ��ϴ� ���� ��
		return 0;
	}
	else if (date[1][0] - date[0][0] >= 2)
		mid(); // �Է¹��� ������ 2 �̻����� ��������
	else
		startend(); // �Է¹��� ������ �׳� 1���̳��ų� ���� ������ ���

		cout << "D-" << sum;
}