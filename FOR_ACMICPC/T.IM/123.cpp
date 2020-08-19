#include <iostream>
using namespace std;
int main() {
	freopen("output.txt", "w", stdout);
	cout << 10000 << ' ' << 9999 << '\n';
	for (int i = 1; i <= 9999; i++)
		cout << i << ' ' << i + 1 << '\n';
	cout << 10000;
	return 0;
}