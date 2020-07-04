#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
	string str;
	bool checker = 0;
	char ch[52];
	int TC;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		int check[52] = { 0 };
		cin >> str;
		strcpy(ch, str.c_str());

		for (int i = 0; i < strlen(ch); i++) {
			if (ch[i] == '(')
				for (int f = i + 1; f < strlen(ch); f++)
					if (ch[f] == ')' && check[f] == 0) {
						check[i] = 1;
						check[f] = 1;
						break;
					}
		}
		for (int i = 0; i < strlen(ch); i++)
			if (check[i] == 0)
				checker = 1;

		if (checker)
			cout << "NO\n";
		else
			cout << "YES\n";

		checker = 0;
	}

}
