#include <iostream>
using namespace std;

int euclid(int a, int b) {
	if (a % b != 0) {
		return euclid(b, a % b);
	}
	else
		return b;
}

int main() {
	int TC, first, last;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> first >> last;
		cout << first * last / euclid(first, last) << "\n";
	}
}