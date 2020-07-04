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
long counter[101] = { 0 };
int gcd(int k, int l) { return l ? gcd(l, k % l) : k; } int lcm(int k, int l) { return k / gcd(k, l) * l; }

void Kv(int ii, int xx, int yy) {
	int not_full = 0;
	for (int i = 1; i < yy; i++)
		not_full += i;
	counter[ii] += (xx - yy) * not_full * 6;
	for (int i = 1; i < yy; i++)
		for (int f = i; f > 0; f--)
			counter[ii] += f * 6; /// ?????
}

void vK(int ii, int xx, int yy) {

}

int main() {
	int tc, x, y;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> x >> y;
		if (x >= y) {
			for (int f = 1; f <= y; f++)	// two distance
				counter[i] += f * 6;
			if (x - y > 0 && y != 0)
				counter[i] += y * (x - y) * 6;
			counter[i] += x + 1;			// one distance
			Kv(i, x, y);				// three distance
		}
		else {
			counter[i] += x + 1;			//one distance
			for (int f = 1; f <= x; f++)
				counter[i] += f * 6;		// two distance
			for (int f = 1; f < x; f++)
				for (int h = f; h > 0; h--)
					counter[i] += h * 6;
		}
		cout << "Case #" << i + 1 << ": " << counter[i] << "\n";
	}

}