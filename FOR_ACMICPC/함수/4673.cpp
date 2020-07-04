#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	int length, checker[10100] = { 0 };

	for (int i = 1; i < 9999; i++) {
		int temp = i, keep = i;
		if (i == 1)
			length = 0;
		if (i == 10)
			length = 1;
		if (i == 100)
			length = 2;
		if (i == 1000)
			length = 3;
		for (int f = length; f >= 0; f--) {
			keep += (temp / (int)pow(10, f));
			temp %= (int)pow(10, f);
		}
		checker[keep] = 1;

		if (checker[i] == 0)
			cout << i << "\n";
	}
}