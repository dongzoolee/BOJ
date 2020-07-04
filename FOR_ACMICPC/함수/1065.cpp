#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;
int counter = 0, length_1 = 0;
int numb[6];

int hansu(int end) {
	for (int i = 1; i <= end; i++) {
		int temp = i;
		bool checker = 0;

		if (i == 1)
			length_1 = 0;
		if (i == 10)
			length_1 = 1;
		if (i == 100)
			length_1 = 2;
		if (i == 1000)
			length_1 = 3;

		if (i >= 10) {
			for (int f = length_1; f >= 0; f--) {
				numb[f] = temp / (int)pow(10, f);
				temp %= (int)pow(10, f);
			}
			for (int h = 1; h <= length_1; h++) {
				if(h != 1)
					if (temp != numb[h] - numb[h - 1])
						checker = 1;
				temp = numb[h] - numb[h - 1];
			}
		}
		if (checker == 0)
			counter++;
	}
	return counter;
}

int main(void) {
	int input;
	cin >> input;

	cout << hansu(input);
}