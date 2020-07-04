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
int arr[501][501];

int main() {
	int n, m, total = 0, max_width = 0, width = 0;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };	// ���� ���� ���� ����
	bool checker[501][501] = { 0 }; // �湮ó���� bool
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];

	// BFS�� �������� ? ������� ���� ������ ����� ��
	// ��������� ��ü ���ڸ� ���鼭 1���� ������ Ȯ���غ�����
	// �湮ó���� ���� ���� �ʴ´�. continue

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) { // arr�� 1�� �������� BFS�� �����Ѵ� = ť�� �����.
			// �̹� �湮�߰ų� ���ʿ� Ž�������� �ƴѰ��
			if (checker[i][f] == 1 || arr[i][f] == 0) continue;
			// ELSE
			total++; // �ڽ�����ó��
			width = 1; // ���� 1�� ���ְ�
			checker[i][f] = 1;	//	�湮ó��
			queue<pair<int, int>> q;	//	��ǥ�� �����ؾ��ϹǷ� pairó��
			q.push({ i,f });	//�ڽ�������ġ(������ġ) push
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int h = 0; h < 4; h++) { // �� �߻��� �ƴѵ� �� +1 -1 ��ǥ�� �迭�� �̸� �־���� for�� ������
					int cur_x = x + dx[h], cur_y = y + dy[h];
					if (arr[cur_x][cur_y] == 0 || checker[cur_x][cur_y] == 1) continue;
					if (cur_x < 0 || cur_y < 0 || cur_x >= n || cur_y >= m) continue;
					width++;
					checker[cur_x][cur_y] = 1;
					q.push({ cur_x,cur_y });
				}
			} // end of while
			//	ť�� ������ max_width Ȯ��
			max_width = max(max_width, width);
		}
	cout << total << '\n' << max_width;

}