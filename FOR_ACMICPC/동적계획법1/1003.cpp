#include <iostream>
using namespace std;

void fibofor(int num) {
	long cur, prev = 1, pprev, temp, count = 2;

	if (num == 0)
		cout << "1 0\n";
	if (num == 1) {
		cout << "0 1\n";
		return;
	}

	while (count != num + 2) {
		if (count == 3 || count == 2)
			cur = 1;
		else
			cur = prev + pprev;
		pprev = prev;
		prev = cur;
		if (count == num)
			cout << cur << " ";
		if (count == num + 1)
			cout << cur << "\n";
		count++;
	}
}

int main(void) {
	int rotation, input;
	cin >> rotation;

	for (int i = 0; i < rotation; i++) {
		cin >> input;
		fibofor(input);
	}
}