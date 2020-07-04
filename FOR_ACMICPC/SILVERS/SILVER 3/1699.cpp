#include <iostream>
#include <math.h>
#include<limits.h>
using namespace std;
int n, temp, min = INT_MAX;

void search(int num, int remain, int count) {
	for (int i = num; i > 0; i--) {
		if (remain - (int)pow(i, 2) != 0)
			search((int)pow(remain - (int)pow(i, 2), 0.5), remain - (int)pow(i, 2), count + 1);
		else if (min > count) {
			count++;
			min = count;
			return;
		}
	}
}

int main() {
	cin >> n;
	temp = n;
	search((int)pow(n, 0.5), temp, 0);
	cout << min;
}