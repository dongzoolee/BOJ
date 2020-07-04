#include <iostream>
using namespace std;

int main(void) {
	int rotation, input[1001], counter[1001] = { 0 }, max_counter = 0;
	cin >> rotation;

	for (int i = 0; i < rotation; i++)
		cin >> input[i];

	for (int i = 0; i < rotation; i++) {
		int main = input[i];

		for (int f = i-1; f >= 0; f--)
			if (input[f] < main) {
				counter[i]++;
				main = input[f];
			}

		main = input[i];
		for (int h = i + 1; h<rotation; h++)
			if (input[h] < main) {
				counter[i]++;
				main = input[h];
			}
	}
	for (int i = 0; i < rotation; i++)
		if (max_counter < counter[i])
			max_counter = counter[i];

	cout << max_counter + 1;

}