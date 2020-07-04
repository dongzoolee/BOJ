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
int M, N, K, counter = 0;
bool og = 1;

void sub_judge(int bat[][50], int x, int y) {
	bat[x][y] = 0;
	if (bat[x + 1][y] == 1)
		sub_judge(bat, x + 1, y);
	if (bat[x][y + 1] == 1)
		sub_judge(bat, x, y + 1);
	if (bat[x - 1][y] == 1 && x != 0)
		sub_judge(bat, x - 1, y);
	if (bat[x][y - 1] == 1 && y != 0)
		sub_judge(bat, x, y - 1);
}
void judge(int bat[][50], int x, int y) {
	while (1)
		if (bat[x][y] == 1) {
			bat[x][y] = 0;
			counter++;
			if (bat[x + 1][y] == 1)
				sub_judge(bat, x + 1, y);
			if (bat[x][y + 1] == 1)
				sub_judge(bat, x, y + 1);
			if (bat[x - 1][y] == 1 && x != 0)
				sub_judge(bat, x - 1, y);
			if (bat[x][y - 1] == 1 && y != 0)
				sub_judge(bat, x, y - 1);
		}
		else if (x == 49 && y != 49) {
			x = 0;
			y++;
		}
		else if (x == 49 && y == 49) {
			return;
		}
		else
			x++;
}
int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int bat[50][50] = { 0 };
		counter = 0;
		cin >> M >> N >> K;

		for (int f = 0; f < K; f++) {
			int x, y;
			cin >> x >> y;
			bat[x][y] = 1;
		}
		judge(bat, 0, 0);
		cout << counter << "\n";
	}

}