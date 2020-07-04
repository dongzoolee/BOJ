#include <iostream>
#include <math.h>
using namespace std;
int rec[102][102];

void arrayinput(int n, int m) {
	string sentence;
	for (int h = 1; h <= n; h++) {
		cin >> sentence;
		for (int f = 1; f <= m; f++) {
			rec[h][f] = sentence.at(f-1) - 48;
		}
	}
}

int main() {
	long long N, M, asum = 0, bsum = 0, csum = 0, temp = 0;
	cin >> N >> M;
	arrayinput(N, M);
	if (N == 1)
		for (int i = 1; i <= M - 2; i++) {
			asum += rec[1][i];
			for (int f = i + 1; f <= M - 1; f++) {
				bsum += rec[1][f];
				for (int h = f + 1; h <= M; h++)
					csum += rec[1][h];
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				bsum = 0, csum = 0;
			}
		}
	else if (M == 1)
		for (int i = 1; i <= N - 2; i++) {
			asum += rec[i][1];
			for (int f = i + 1; f <= N - 1; f++) {
				bsum += rec[f][1];
				for (int h = f + 1; h <= N; h++)
					csum += rec[h][1];
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				bsum = 0, csum = 0;
			}
		}
	else {
		// 왼쪽부터 세로쭉으로 시작
		for (int i = 1; i < M; i++) {
			for (int f = 1; f <= N; f++) // 첫사각형의 한줄쫙
				asum += rec[f][i];
			for (int h = i + 1; h < M; h++) {// 두번째 사각형 x축으로 하나씩 하나씩++
				for (int g = 1; g <= N; g++) { // 두&세번째 사각형의 y값증가
					bsum += rec[g][h];
					for (int y = h + 1; y <= M; y++) //remaining x축 먼저 다 먹기
						csum += rec[g][y];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;

			for (int h = 1; h < N; h++) {// 두번째 사각형 y축으로 하나씩 하나씩++
				for (int g = i+1; g <= M; g++) { // 두&세번째 사각형의 x값증가
					bsum += rec[h][g];
					for (int y = h + 1; y <= N; y++) //remaining y축 먼저 다 먹기
						csum += rec[y][g];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;
		}
		asum = 0;
		// 오른쪽부터 세로쭉으로 시작
		for (int i = M; i > 1; i--) {
			for (int f = 1; f <= N; f++) // 첫사각형의 한줄쫙
				asum += rec[f][i];
			for (int h = i - 1; h > 1; h--) {// 두번째 사각형 x축으로 하나씩 하나씩++
				for (int g = 1; g <= N; g++) { // 두&세번째 사각형의 y값증가
					bsum += rec[g][h];
					for (int y = h - 1; y > 0; y--) //remaining x축 먼저 다 먹기
						csum += rec[g][y];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;

			for (int h = 1; h < N; h++) {// 두번째 사각형 y축으로 하나씩 하나씩++
				for (int g = i - 1; g > 0; g--) { // 두&세번째 사각형의 x값증가
					bsum += rec[h][g];
					for (int y = h + 1; y <= N; y++) //remaining y축 먼저 다 먹기
						csum += rec[y][g];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;
		}
		asum = 0;
		// 위쪽부터 가로쭉으로 시작
		for (int i = 1; i < N; i++) {
			for (int f = 1; f <= M; f++) // 첫사각형의 한줄쫙
				asum += rec[i][f];

			for (int h = i + 1; h < N; h++) {
				for (int g = 1; g <= M; g++) { // 두&세번째 사각형의 y값증가
					bsum += rec[h][g];
					for (int y = h + 1; y <= N; y++) //remaining x축 먼저 다 먹기
						csum += rec[y][g];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;

			for (int h = 1; h < M; h++) {// 두번째 사각형 x축으로 하나씩 하나씩++
				for (int g = i+1; g <= N; g++) { // 두&세번째 사각형의 y값증가
					bsum += rec[g][h];
					for (int y = h + 1; y <= M; y++) //remaining x축 먼저 다 먹기
						csum += rec[g][y];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;
		}
		asum = 0;
		// 아래쪽부터 시작
		for (int i = N; i > 1; i--) {
			for (int f = 1; f <= M; f++) // 첫사각형의 한줄쫙
				asum += rec[i][f];

			for (int h = i - 1; h > 1; h--) {
				for (int g = 1; g <= M; g++) { // 두&세번째 사각형의 y값증가
					bsum += rec[h][g];
					for (int y = h - 1; y >= 1; y--) //remaining x축 먼저 다 먹기
						csum += rec[y][g];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;

			for (int h = 1; h < M; h++) {// 두번째 사각형 x축으로 하나씩 하나씩++
				for (int g = i - 1; g > 0; g--) { // 두&세번째 사각형의 y값증가
					bsum += rec[g][h];
					for (int y = h + 1; y <= M; y++) //remaining x축 먼저 다 먹기
						csum += rec[g][y];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;
		}
	}
	cout << temp;
}