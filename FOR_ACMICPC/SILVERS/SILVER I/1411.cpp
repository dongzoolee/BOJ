#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
int n, counter = 0;
char ch[51][51], checking[51] = { 0 };

void _search(int one, int two, int length, vector<char[51]> v) {
	for (int i = 1; i < length; i++)
		if (ch[one][i] != ch[two][i]) {
			checking[one] = checking[two] = 1;
			break;
		}
}

int main() {
	int che_alpha[26] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%s", ch[i]);

	for (int i = 0; i < n; i++) {
		vector <char[51]>vec;
		if (che_alpha[ch[i][0]] == 0) {
			vec.push_back(ch[i]);
			for (int f = i + 1; f < n; f++)
				if (che_alpha[ch[i][0]] == che_alpha[ch[f][0]])
					vec.push_back(ch[f]);
			_search(i, i, strlen(ch[i]), vec);
			che_alpha[ch[i][0]] = 1;
		}
	}
	for (int i = 0; i < 51; i++)
		if (checking[i] == 1)
			counter++;
	cout << counter;
}