#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
using ll = long long;
vector<string>v[20];
vector<char>alph[20];
// n  index == 10
// ng index == 11

void preset() {
	alph[0].push_back('a');
	alph[1].push_back('b');
	alph[2].push_back('k');
	alph[3].push_back('d');
	alph[4].push_back('e');
	alph[5].push_back('g');
	alph[6].push_back('h');
	alph[7].push_back('i');
	alph[8].push_back('l');
	alph[9].push_back('m');
	alph[10].push_back('n');
	alph[11].push_back(' ');
	alph[12].push_back('o');
	alph[13].push_back('p');
	alph[14].push_back('r');
	alph[15].push_back('s');
	alph[16].push_back('t');
	alph[17].push_back('u');
	alph[18].push_back('w');
	alph[19].push_back('y');
}
	void judge() {
	for (int i = 0; i < 20; i++) {
		if (v[i].size() == 1) {
			cout << v[i].front() << "\n";
		}
		else {















		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	preset();
	int tc; string str;
	for (int i = 0; i < tc; i++) {
		cin >> str;
		alph[str[0]]
	}

	judge();
}