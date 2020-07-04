#include <algorithm>
#include <iostream>
using namespace std;
int rotation, input[1000000];

int main(void) {
	cin >> rotation;

	for (int i = 0; i < rotation; i++)
		cin >> input[i];

	sort(input, input + rotation);
	for (int i = 0; i < rotation; i++)
		cout << input[i] << "\n";
}