#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;

int main() {
	int tc, prev;
	string str;

	char ch[61] = { 0 };
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		bool protocol = 0, port = 0, path = 0;
		cin >> str;
		strcpy(ch, str.c_str());
		cout << "URL #" << i + 1 << "\n";
		for (int f = 0; f < strlen(ch); f++) {
			if (ch[f] == ':' && protocol == 0) {
				protocol = 1;
				cout << "Protocol = ";
				for (int h = 0; h < f; h++)
					cout << ch[h];
				cout << "\n";
				f += 2;
				prev = f;
				continue;
			}
			else if (ch[f] == ':' || (protocol == 1 && port == 0 && f == strlen(ch) -1)) {
				if (protocol == 1 && port == 0 && f == strlen(ch) - 1) {
					cout << "Host     = ";
					for (int h = prev + 1; h < strlen(ch); h++)
						cout << ch[h];
					cout << "\nPort     = <default>\nPath     = <default>\n\n";
					break;
				}
				port = 1;
				cout << "Host     = ";
				for (int h = prev + 1; h < f; h++)
					cout << ch[h];
				cout << "\n";
				prev = f;
				continue;
			}
			else if ((ch[f] == '/' && protocol == 1) || (protocol == 1 && f == strlen(ch) - 1)) {
				if (protocol == 1 && f == strlen(ch) - 1) {	// 걍 path가 없는 거임.
					cout << "Port     = "; 
					for (int h = prev + 1; h < strlen(ch) && ch[h]!='/'; h++)
						cout << ch[h];
					cout<< "\nPath     = <default>\n\n";
					break;
				}
				if (port == 0) {
					cout << "Host     = ";
					for (int h = prev + 1; h < f; h++)
						cout << ch[h];
					cout << "\nPort     = <default>\nPath     = ";
					for (int h = f + 1; h < strlen(ch); h++)
						cout << ch[h];
					cout << "\n\n";
					break;
				}
				else {
					cout << "Port     = ";
					for (int h = prev + 1; h < f; h++)
						cout << ch[h];
					cout << "\nPath     = ";
					for (int h = f + 1; h < strlen(ch); h++)
						cout << ch[h];
					cout << "\n\n";
					break;
				}
			}
		}
	}
}