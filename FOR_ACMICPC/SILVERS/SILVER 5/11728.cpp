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
vector<int> vec;
vector<int> vec2;
int length = vec.size();

int binsrch(int target) {
	int low = 0;
	int high = length - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (vec[mid] == target)
			return 1; //찾음
		else if (vec[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0; //못찾음
}

int main() {
	int N, M, input;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);
	}
	int f = 0, h = vec.size();

	for (int i = 0; i < M; i++) {
		cin >> input;
		if (f != h) {
			if (!binsrch(input))
				while (1)
					if (vec[f] < input) {
						cout << vec[f++] << " ";
						if (f == h) {
							cout << input << " ";
							break;
						}
					}
					else if (vec[f] > input) {
						cout << input << " ";
						break;
					}
					else {
						cout << vec[f++] << " ";
						break;
					}
		}
		else
			cout << input << " ";
	}

	if (f != h)
		while (f != h)
			cout << vec[f++] << " ";
}