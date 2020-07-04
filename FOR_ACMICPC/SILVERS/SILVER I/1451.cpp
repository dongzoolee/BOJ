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
		// ���ʺ��� ���������� ����
		for (int i = 1; i < M; i++) {
			for (int f = 1; f <= N; f++) // ù�簢���� ������
				asum += rec[f][i];
			for (int h = i + 1; h < M; h++) {// �ι�° �簢�� x������ �ϳ��� �ϳ���++
				for (int g = 1; g <= N; g++) { // ��&����° �簢���� y������
					bsum += rec[g][h];
					for (int y = h + 1; y <= M; y++) //remaining x�� ���� �� �Ա�
						csum += rec[g][y];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;

			for (int h = 1; h < N; h++) {// �ι�° �簢�� y������ �ϳ��� �ϳ���++
				for (int g = i+1; g <= M; g++) { // ��&����° �簢���� x������
					bsum += rec[h][g];
					for (int y = h + 1; y <= N; y++) //remaining y�� ���� �� �Ա�
						csum += rec[y][g];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;
		}
		asum = 0;
		// �����ʺ��� ���������� ����
		for (int i = M; i > 1; i--) {
			for (int f = 1; f <= N; f++) // ù�簢���� ������
				asum += rec[f][i];
			for (int h = i - 1; h > 1; h--) {// �ι�° �簢�� x������ �ϳ��� �ϳ���++
				for (int g = 1; g <= N; g++) { // ��&����° �簢���� y������
					bsum += rec[g][h];
					for (int y = h - 1; y > 0; y--) //remaining x�� ���� �� �Ա�
						csum += rec[g][y];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;

			for (int h = 1; h < N; h++) {// �ι�° �簢�� y������ �ϳ��� �ϳ���++
				for (int g = i - 1; g > 0; g--) { // ��&����° �簢���� x������
					bsum += rec[h][g];
					for (int y = h + 1; y <= N; y++) //remaining y�� ���� �� �Ա�
						csum += rec[y][g];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;
		}
		asum = 0;
		// ���ʺ��� ���������� ����
		for (int i = 1; i < N; i++) {
			for (int f = 1; f <= M; f++) // ù�簢���� ������
				asum += rec[i][f];

			for (int h = i + 1; h < N; h++) {
				for (int g = 1; g <= M; g++) { // ��&����° �簢���� y������
					bsum += rec[h][g];
					for (int y = h + 1; y <= N; y++) //remaining x�� ���� �� �Ա�
						csum += rec[y][g];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;

			for (int h = 1; h < M; h++) {// �ι�° �簢�� x������ �ϳ��� �ϳ���++
				for (int g = i+1; g <= N; g++) { // ��&����° �簢���� y������
					bsum += rec[g][h];
					for (int y = h + 1; y <= M; y++) //remaining x�� ���� �� �Ա�
						csum += rec[g][y];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;
		}
		asum = 0;
		// �Ʒ��ʺ��� ����
		for (int i = N; i > 1; i--) {
			for (int f = 1; f <= M; f++) // ù�簢���� ������
				asum += rec[i][f];

			for (int h = i - 1; h > 1; h--) {
				for (int g = 1; g <= M; g++) { // ��&����° �簢���� y������
					bsum += rec[h][g];
					for (int y = h - 1; y >= 1; y--) //remaining x�� ���� �� �Ա�
						csum += rec[y][g];
				}
				if (temp < asum * bsum * csum)
					temp = asum * bsum * csum;
				csum = 0;
			}
			bsum = 0;

			for (int h = 1; h < M; h++) {// �ι�° �簢�� x������ �ϳ��� �ϳ���++
				for (int g = i - 1; g > 0; g--) { // ��&����° �簢���� y������
					bsum += rec[g][h];
					for (int y = h + 1; y <= M; y++) //remaining x�� ���� �� �Ա�
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