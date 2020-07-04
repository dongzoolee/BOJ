#include<iostream>
using namespace std;
int date[3][4];
long sum = 0;

bool y_p(int year) {
	if ((year % 4 == 0 && year % 100 !=0) || year%400 ==0) {
		//윤년
		return 1;
	}
	else{
		//평년
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
		//시작달
		if (y_p(date[0][0]) == 1) { // 윤년일 경우
			if (date[0][1] == 2)
				sum += (29 - date[0][2]);
			else if (date[0][1] == 4 || date[0][1] == 6 || date[0][1] == 9 || date[0][1] == 11)
				sum += (30 - date[0][2]);
			else
				sum += (31 - date[0][2]);
		}
		else {						// 평년일 경우
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
	else { // 연도랑 월까지 같아 버릴경우
		sum = date[1][2] - date[0][2];
		return;
	}
}

void mid() {
	int temp = date[0][0] + 1;
	while (temp < date[1][0]) { // 두 연도 사이에 낀 날(日)들을 count (처음, 끝 제외)
		if ((temp % 4 == 0 && temp % 100 != 0) || temp % 400 == 0) {
			//윤년
			sum += 366;
		}
		else {
			//평년
			sum += 365;
		}

		temp++;
	}
	startend(); // 처음, 끝 계산하러가기
}

int main() {
	for (int i = 0; i < 2; i++)
		for (int f = 0; f < 3; f++)
			cin >> date[i][f];

	if ((date[1][0] - date[0][0] == 1000 && (date[1][1]>date[0][1] || (date[1][1]==date[0][1] && date[1][2]>=date[0][2]))) || date[1][0] - date[0][0] > 1000) {
		cout << "gg"; //진짜 골때린다..... 1000년 이상을 판단하는 기준 ↑
		return 0;
	}
	else if (date[1][0] - date[0][0] >= 2)
		mid(); // 입력받은 연도가 2 이상으로 벌어지면
	else
		startend(); // 입력받은 연도가 그냥 1차이나거나 같은 연도일 경우

		cout << "D-" << sum;
}