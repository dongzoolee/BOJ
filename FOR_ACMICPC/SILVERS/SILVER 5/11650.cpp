#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
using namespace std;
int xaxis, yaxis;
vector<pair<int, int>> vec;

int main(void) {
	int rotation, inx, iny;
	cin >> rotation;
	
	for (int i = 0; i < rotation; i++) {
		cin >> xaxis >> yaxis;
		vec.push_back({xaxis, yaxis});
	}

	sort(begin(vec), end(vec), [] (auto a, auto b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first < b.first;
		});

	for (int i = 0; i < rotation; i++)
		cout << vec[i].first << " " << vec[i].second << "\n";

}