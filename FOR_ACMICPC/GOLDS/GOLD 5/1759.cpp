#include <iostream>
#include <algorithm>
using namespace std;
int L, C, isitforfirst = 0;
char ch[16], arr[16];

void printer(int returncounter, int aeiou, int n, int forfirstisit, bool aeiouchecker) {

	for (int i = returncounter; i < C - L + forfirstisit + 1; i++) {
		if (forfirstisit == 0) {
			n = 0;
			aeiou = 0;
		}
		if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') {
			aeiou++;
			aeiouchecker = 1;
		}
		else
			aeiouchecker = 0; 

		if (n != L-1) {
			arr[n] = ch[i];
			printer(i + 1, aeiou, n + 1, forfirstisit + 1, 0);
		}
		else {
			arr[n] = ch[i];
			if (L - aeiou >= 2 && aeiou != 0) {
				for (int i = 0; i < L; i++)
					cout << arr[i];
					cout << "\n";
			}
		}
		if (aeiouchecker == 1)
			aeiou--;
	}//end of for
}//end of printer

int main() {

	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> ch[i];
	sort(ch, ch + C);
	printer(0, 0, 0, 0, 0);

}