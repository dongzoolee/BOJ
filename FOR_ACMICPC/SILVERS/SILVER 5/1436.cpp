#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

int main() {
	int n, counter, numcount = 0;
	cin >> n;

	for (int i = 666;; i++) {
		counter = 0;
		int temp = i;
		for (int f = (int)log10(i)-1; f > 0; f--) {
			if (temp % 1000 == 666) {
				counter = 1;
				break;
			}
			temp /= 10;
		}
		if (counter == 1)
			numcount++;
		if (numcount == n) {
			cout << i;
			break;
		}
	}
}