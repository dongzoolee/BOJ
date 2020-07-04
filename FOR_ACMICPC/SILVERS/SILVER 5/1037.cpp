#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	long divisor_num, divisor[52];
	cin >> divisor_num;

	for (int i = 0; i < divisor_num; i++)
		cin >> divisor[i];
	sort(divisor, divisor + divisor_num);
	if (divisor_num % 2 == 0)// Â¦¼ö°³
		cout << divisor[0] * divisor[divisor_num - 1];
	else if (divisor_num == 1) // ¾à¼ö ÇÏ³ª
		cout << (long)pow(divisor[0], 2);
	else // È¦¼ö°³
		cout << (long)pow(divisor[divisor_num / 2], 2);

}