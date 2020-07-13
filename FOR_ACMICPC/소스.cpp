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
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	FILE* output;
	output = fopen("input.txt", "w");
	fprintf(output, "100000\n");
	for (int i = -50000; i <=50000; i++) {
		if(i!=0)
		fprintf(output, "%d ", i);
	}
}