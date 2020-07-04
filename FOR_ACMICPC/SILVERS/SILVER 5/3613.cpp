#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
	string str;
	char ch[101];
	bool check_ = 0, checkA = 0;
	cin >> str;
	strcpy(ch, str.c_str());

	//ERROR condition
	for (int i = 0; i < strlen(ch); i++) {
		if (!(97 <= ch[0] && ch[0] <= 122) || (ch[i-1] == '_' && (65 <= ch[i] && ch[i] <= 90)) || ch[strlen(ch)-1] == '_' || (ch[i-1] == '_' && ch[i] == '_')) {
			cout << "Error!";
			return 0;
		}
		if (65 <= ch[i] && ch[i] <= 90)
			checkA = 1;
		if (ch[i] == 95)
			check_ = 1;
	}
	if (checkA == 1 && check_ == 1) {
		cout << "Error!";
		return 0;
	}

	for (int i = 0; i < strlen(ch); i++) {
		if (65 <= ch[i] && ch[i] <= 90)
			goto CI;
		else if (ch[i] == 95)
			goto CII;
	}

	//if JAVA
CI:	for (int i = 0; i < strlen(ch); i++) {
	if (65 <= ch[i] && ch[i] <= 90) {
		ch[i] += 32;
		cout << "_" << ch[i];

		if (i == strlen(ch) - 1)
			return 0;
		else
			continue;
	}
	cout << ch[i];
	if (i == strlen(ch) - 1)
		return 0;
}

//if C++
CII:	for (int i = 0; i < strlen(ch); i++) {
			if (ch[i] == 95)
				ch[i + 1] -= 32;
			else
				cout << ch[i];
		}
}