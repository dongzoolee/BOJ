#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void) {
	int rotation, input, num[100001], zero_counter = 0, after_input = 0, zero_i = 0;
	long sum = 0;
	cin >> rotation;
	for (int i = 0; i < rotation; i++) {
		cin >> input;
		if (input == 0) {
			zero_counter++;
			zero_i = i;
		}
		else {
			if (zero_i + 1 == i && i != 1) {
				for (int f = after_input-1; f > after_input-zero_counter-1; f--)
					sum -= num[f];
				sum += input;
				num[after_input - zero_counter] = input;
				after_input -= (zero_counter-1);
				zero_counter = 0;
				continue;
			}
			sum += input;
			num[after_input] = input;
			after_input++;
		}
	}
	if(zero_counter==0)
		cout << sum;
	else {
		for (int f = after_input - 1; f > after_input - zero_counter - 1; f--)
			sum -= num[f];
		cout << sum;
	}
}