#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
	int num, n = 0, m = 0;
	string str;
	char ch[201], object[201];
	cin >> num;
	cin >> str;
	strcpy(ch, str.c_str());

	for (int f = 1; f <= (strlen(ch) / num); f++) {
		n = f;
		if(f%2!=0)
			for (int i = 0; i < num; i++) {
				object[n] = ch[m++];
				if (i != num - 1)
					n += (strlen(ch) / num);
			}
		else
			for (int i = 0; i < num; i++) {
				if (i == 0)
					n += (num - 1) * (strlen(ch) / num);
				object[n] = ch[m++];
				if (i != num - 1)
					n -= (strlen(ch) / num);
			}
	}
	for (int i = 1; i <= strlen(ch); i++)
		cout << object[i];
}