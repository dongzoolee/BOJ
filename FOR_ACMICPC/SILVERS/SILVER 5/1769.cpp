#include <iostream>
#include <math.h>
#include <string>
using namespace std;
string sentence;
int length, counter = 0, sum = 0, temp;

void sentenceinput() {
		for (int f = 1; f <= sentence.length(); f++) {
			sum += sentence.at(f - 1) - 48;
		}
		if (sentence.length() != 1)
			counter++;
}

int main() {
	cin >> sentence;
	sentenceinput();
	int input = sum;
	while ((int)log10(input) + 1 != 1) {
		sum = 0;
		length = (int)log10(input) + 1;

		temp = input;
		for (int i = length - 1; i >= 0; i--) {
			sum += temp / (int)pow(10, i);
			temp %= (int)pow(10, i);
		}
		counter++;
		input = sum;
	}
	cout << counter << "\n";
	if (input % 3 == 0)cout << "YES"; else cout << "NO";

}