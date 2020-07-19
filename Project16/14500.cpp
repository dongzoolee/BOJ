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
int arr[500][500], n, m, max_ = 0;

void tetris() {
	// �� ĭ���� 5���� ������ ����Ѵ�.
	// if������ ��Ʈ�ι̳��� �װ��� ��ǥ�� NxM���� �ִ��� �ѹ��� üũ�Ѵ�.

	for (int i = 0; i < n; i++) // y��ǥ
		for (int f = 0; f < m; f++) { // x��ǥ
			// ��������
			if (f + 3 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i][f + 2] + arr[i][f + 3]);
			if (f - 3 >=0)
				max_ = max(max_, arr[i][f] + arr[i][f - 1] + arr[i][f - 2] + arr[i][f - 3]);
			if (i + 3 < n)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 2][f] + arr[i + 3][f]);
			if (i - 3 >=0 )
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 2][f] + arr[i - 3][f]);
			// ����
			// ����
			if (i + 1 < n && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i + 1][f] + arr[i + 1][f + 1]);
			// ��
			// ��
			// ����
			if (i + 2 < n && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 2][f] + arr[i + 2][f + 1]);
			if (i + 2 < n && f - 1 >=0)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 2][f] + arr[i + 2][f - 1]);
			if (i - 2 >= 0 && f - 1 >=0)
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 2][f] + arr[i - 2][f - 1]);
			if (i - 2 >= 0 && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 2][f] + arr[i - 2][f + 1]);
			// ��
			// ������
			if (i + 1 < n && f + 2 < m)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 1][f + 1] + arr[i + 1][f + 2]);
			if (i + 1 < n && f - 2 >= 0)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 1][f - 1] + arr[i + 1][f - 2]);
			if (i - 1 >=0 && f + 2 <m)
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 1][f + 1] + arr[i - 1][f + 2]);
			if (i - 1 >=0 && f - 2 >= 0)
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 1][f - 1] + arr[i - 1][f - 2]);
			// ��
			// ����
			//   ��
			if (i + 2 < n && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 1][f + 1] + arr[i + 2][f + 1]);
			if (i + 2 < n && f - 1 >= 0)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 1][f - 1] + arr[i + 2][f - 1]);
			// ����
			//   ����
			if (i + 1 < n && f + 2 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i + 1][f + 1] + arr[i + 1][f + 2]);
			if (i + 1 < n && f - 2 >= 0)
				max_ = max(max_, arr[i][f] + arr[i][f - 1] + arr[i + 1][f - 1] + arr[i + 1][f - 2]);
			// ������
			//   ��
			if (i + 1 < n && f + 2 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i][f + 2] + arr[i + 1][f + 1]);
			if (i - 1 >= 0 && f + 2 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i][f + 2] + arr[i - 1][f + 1]);
			// ��
			// ����
			// ��
			if (i + 2 < n && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 2][f] + arr[i + 1][f + 1]);
			if (i + 2 < n && f - 1 >= 0)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 2][f] + arr[i + 1][f - 1]);
		}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];

	tetris();
	cout << max_;
}