#include <iostream>
using namespace std;

int main(void) {
	long input[125251] = { 0 }, arr[125251] = { 0 }, rotation, line = 0, line_sum = 0, max = 0;
	cin >> rotation;
	for (long i = 0; i < (rotation * (rotation + 1)) / 2; i++) {
		cin >> input[i];

		if (i == 0)
			arr[0] = input[0];
	}
	for (long line = 1; line < rotation; line++) {
		line_sum += line;
		for (long f = line_sum-line; f < line_sum; f++) {
			if (arr[f + line] < input[f + line] + arr[f]) {
				arr[f + line] = arr[f] + input[f + line];
				if (line == rotation-1 && arr[f + line] > max)
					max = arr[f + line];
			}
			if (arr[f + line + 1] < input[f + line + 1] + arr[f]) {
				arr[f + line + 1] = arr[f] + input[f + line + 1];
				if (line == rotation-1 && arr[f + line + 1] > max)
					max = arr[f + line + 1];
			}
		}
	}
	cout << max;
}