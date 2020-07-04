#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int score[10], arr[10], sum = 0, fsort[5], n = 0;

	for (int i = 1; i < 9; i++) {
		cin >> score[i];
		arr[i - 1] = score[i];
	}
	sort(arr, arr + 8);

	for (int i = 7; i > 2; i--)
		sum += arr[i];

	cout << sum << "\n";
	for (int i = 7; i > 2; i--)
		for (int f = 1; f < 9; f++)
			if (arr[i] == score[f])
				fsort[n++] = f;
	sort(fsort, fsort + 5);
	for (int i = 0; i < 5; i++)
		cout << fsort[i] << " ";
}