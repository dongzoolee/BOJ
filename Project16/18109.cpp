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
int arr[58] = { 0 };
int cnt = 0;
string str;
void init() {
	string a[3];
	a[0] = "rsefaqtdwczxvg", a[1] = "REQTW", a[2] = "kijuhynbmlopOP";
	for (int i = 0; i < a[0].length(); i++)
		arr[a[0][i] - 'A'] = 0;
	for (int i = 0; i < a[1].length(); i++)
		arr[a[1][i] - 'A'] = 1;
	for (int i = 0; i < a[2].length(); i++)
		arr[a[2][i] - 'A'] = 2;
	//���� == 0
	//rsefaqtdwczxvg 
	// REQTW /ħ���Ұ� == 1

	//���� == 2
	//kijuhynbmlop
}
void judge(int u, int v) {
	//�������� ���� �ִ� 3�� 
	if (v - u == 4) { // 3
		return;
	}
	if (v - u == 3) { // 2
		// �� ������ ��������
		if (str[u + 1] == 'R' || str[u + 1] == 'E' || str[u + 1] == 'Q' || str[u + 1] == 'T' || str[u + 1] == 'W')
		{
		}
		else if ((str[u + 1] == 'r'&&str[v + 1] == 't') || (str[u + 1] == 's' && (str[v + 1] == 'w' || str[v + 1] == 'g' || str[v + 1] == 'r' || str[v + 1] == 'a' || str[v + 1] == 'q' || str[v + 1] == 't' || str[v + 1] == 'x' || str[v + 1] == 'v' || str[v + 1] == 'g')) || (str[u + 1] == 'q' && str[v + 1] == 't'))
			cnt++;
		/* or ������ �Ұ�����*/
	 //
	}
	if (v - u == 2) { // 1
		if (str[u + 1] == 'Q' || str[u + 1] == 'W' || str[u + 1] == 'E')
		{
		}
		else
			cnt++;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	getline(cin, str);
	init();
	int tmp = -1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			tmp = -1; // ��� ������ �ȳ��Դ�

		if (arr[str[i] - 'A'] == 2 && tmp == -1)
			tmp = i;

		if (arr[str[i] - 'A'] == 2 && tmp != -1) {
			if (i - tmp > 1) // ����+����+���� => cnt++
				judge(tmp, i);
			tmp = i;
		}
	}
	cout << cnt;
}