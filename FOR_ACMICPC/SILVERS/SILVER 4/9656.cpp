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
	int n;
	cin >> n;
		
	if (n % 2 == 0)
		cout << "SK";
	else
		cout << "CY";
}