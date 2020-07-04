#include <iostream>
#include <string>
using namespace std;
int arr[13], about_date[6];
char ch[20];
void year(int yr);

void printing_area() {
	// 월이 같을 때
	if (about_date[0] == about_date[3]) {
		year(about_date[2]);
		if (about_date[1] - about_date[4] > 0 && about_date[1] - about_date[4] <= 7) {
			cout << about_date[3] << "/" << about_date[4] << "/" << about_date[2] << " IS " << about_date[1] - about_date[4] << " DAY"; about_date[1] - about_date[4] == 1 ? cout << " PRIOR\n" : cout << "S PRIOR\n";
		}
		else if (about_date[4] - about_date[1] > 0 && about_date[4] - about_date[1] <= 7) {
			cout << about_date[3] << "/" << about_date[4] << "/" << about_date[2] << " IS " << about_date[4] - about_date[1] << " DAY"; about_date[4] - about_date[1] == 1 ? cout << " AFTER\n" : cout << "S AFTER\n";
		}
		else if (about_date[4] == about_date[1])
			cout << "SAME DAY\n";
		else
			cout << "OUT OF RANGE\n";
		return;
	}
	else {
		if (about_date[0] != 1 && about_date[1] - 7 <= 0) {	// 이전 달 침범 CASE 근데 1월은 아님
			year(about_date[2]);
			if (about_date[1] - 7 <= 0 && about_date[3] == about_date[0] - 1 && about_date[4] >= arr[about_date[0] - 1] - 7 + about_date[1]) {
				cout << about_date[3] << "/" << about_date[4] << "/" << about_date[2] << " IS " << about_date[1] + arr[about_date[0] - 1] - about_date[4] << " DAY"; about_date[1] + arr[about_date[0] - 1] - about_date[4] == 1 ? cout << " PRIOR\n" : cout << "S PRIOR\n";
				return;
			}
		}
		else { // 1월인데 12월까지 침범하는 CASE
			year(about_date[2] - 1);
			if (12 == about_date[3] && about_date[4] >= arr[12] - 7 + about_date[1]) {
				cout << about_date[3] << "/" << about_date[4] << "/" << about_date[2] - 1 << " IS " << about_date[1] + arr[12] - about_date[4] << " DAY"; about_date[1] + arr[12] - about_date[4] == 1 ? cout << " PRIOR\n" : cout << "S PRIOR\n";
				return;
			}
		}
		if (about_date[0] != 12 && about_date[1] + 7 <= arr[12]) {
			year(about_date[2]);
			// 다음 달 포함 O 'AFTER'
			if (about_date[1] + 7 > arr[about_date[0]] && 7 - arr[about_date[0]] + about_date[1] >= about_date[4] && about_date[0] + 1 == about_date[3]) {
				cout << about_date[3] << "/" << about_date[4] << "/" << about_date[2] << " IS " << arr[about_date[0]] - about_date[1] + about_date[4] << " DAY"; arr[about_date[0]] - about_date[1] + about_date[4] == 1 ? cout << " AFTER\n" : cout << "S AFTER\n";
				return;
			}
		}
		else { // 12월인데 1월까지 침범하는 CASE
			year(about_date[2]);
			if (1 == about_date[3] && about_date[4] <= 7 - arr[12] + about_date[1]) {
				cout << about_date[3] << "/" << about_date[4] << "/" << about_date[2] + 1 << " IS " << arr[12] - about_date[1] + about_date[4] << " DAY"; arr[12] - about_date[1] + about_date[4] == 1 ? cout << " AFTER\n" : cout << "S AFTER\n";
				return;
			}
		}
	}
}

void year(int yr) {
	bool yoon = 1;
	if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0)
		yoon = 1; // 윤년
	else
		yoon = 0; // 평년

	for (int i = 1; i < 13; i++)
		if (yoon == 1) {
			if (i == 2)
				arr[i] = 29;
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				arr[i] = 30;
			else
				arr[i] = 31;
		}
		else {
			if (i == 2)
				arr[i] = 28;
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				arr[i] = 30;
			else
				arr[i] = 31;
		}
}

int main() {
	int TC;
	string input;
	scanf("%d\n", &TC);

	for (int i = 0; i < TC; i++) {
		scanf("%d/%d/%d %d/%d", &about_date[0], &about_date[1], &about_date[2], &about_date[3], &about_date[4]);

		printing_area();
	}
}