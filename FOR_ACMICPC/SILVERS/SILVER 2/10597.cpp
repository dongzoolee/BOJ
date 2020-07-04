#include <iostream>
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
using longs = long long;
string str;
int stln, cnt;

void judge(vector<int> v) {
	vector<int> temp;
	temp = v;
	sort(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] != i+1)	
			return;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	exit(0);
}

void search(vector<int> v, int index) {
	if (index == stln) { judge(v); return; }
	if (index > stln) return;

	if (str[index] - '0' != 0 && find(v.begin(),v.end(), str[index] - '0')==v.end()) { // ¸Ç ³¡ index + 1 == vec.end
		v.push_back(str[index] - '0');
		search(v, index + 1);
		v.pop_back();
	}
	if (str[index] - '0' != 0 && str[index] - '0' <= cnt && find(v.begin(), v.end(), (str[index] - '0') * 10 + str[index + 1] - '0') == v.end()) {
		v.push_back((str[index] - '0') * 10 + str[index + 1] - '0');
		search(v, index + 2);
	}
}

int main() {
	vector <int> vec;
	cin >> str;
	stln = str.length();
	if (stln <= 9)
		cnt = 1;
	else if (stln <= 29)
		cnt = 1;
	else if (stln <= 49)
		cnt = 2;
	else if (stln <= 69)
		cnt = 3;
	else if (stln <= 89)
		cnt = 4;
	else		cnt = 5;
	search(vec, 0);
}