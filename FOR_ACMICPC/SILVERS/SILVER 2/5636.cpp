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
int arr[100001] = { 0 };

void prime() {
	arr[1] = 1;
	for (int i = 2; i <= 100000; i++)
		for (int f = i + i; f <= 100000; f += i)
			arr[f] = 1;
}

int main() {
	int x;
	string input;
	char ch[7];
	prime();
	
	while (1) {
		int counter = 0, max_ = 0;
		cin >> input;
		if (input == "0") break;
		for (int i = 1; i < 6 && input.length() >= i; i++) { 
			int z = 0;
			queue <int> temp;
			queue <int> q;
			for (int f = 0; f < i; f++)
				temp.push(input[f] - '0');
			while (i + z <= input.length()) {
				q = temp;
				int x = 0;
				for (int h = q.size() - 1; h >= 0; h--) {
					x += q.front() * (int)pow(10, h);
					q.pop();
				}
				if (arr[x] == 0) max_ = max(max_, x);
				temp.pop();
				if (i + z < input.length())
					temp.push(input[i + z++] - '0');
				else
					break;
			}
		}
		cout << max_ << "\n";
	}
}