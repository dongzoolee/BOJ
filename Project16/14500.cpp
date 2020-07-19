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
	// 한 칸에서 5번의 실행을 모두한다.
	// if문으로 테트로미노의 네개의 좌표가 NxM내에 있는지 한번에 체크한다.

	for (int i = 0; i < n; i++) // y좌표
		for (int f = 0; f < m; f++) { // x좌표
			// ㅁㅁㅁㅁ
			if (f + 3 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i][f + 2] + arr[i][f + 3]);
			if (f - 3 >=0)
				max_ = max(max_, arr[i][f] + arr[i][f - 1] + arr[i][f - 2] + arr[i][f - 3]);
			if (i + 3 < n)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 2][f] + arr[i + 3][f]);
			if (i - 3 >=0 )
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 2][f] + arr[i - 3][f]);
			// ㅁㅁ
			// ㅁㅁ
			if (i + 1 < n && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i + 1][f] + arr[i + 1][f + 1]);
			// ㅁ
			// ㅁ
			// ㅁㅁ
			if (i + 2 < n && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 2][f] + arr[i + 2][f + 1]);
			if (i + 2 < n && f - 1 >=0)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 2][f] + arr[i + 2][f - 1]);
			if (i - 2 >= 0 && f - 1 >=0)
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 2][f] + arr[i - 2][f - 1]);
			if (i - 2 >= 0 && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 2][f] + arr[i - 2][f + 1]);
			// ㅁ
			// ㅁㅁㅁ
			if (i + 1 < n && f + 2 < m)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 1][f + 1] + arr[i + 1][f + 2]);
			if (i + 1 < n && f - 2 >= 0)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 1][f - 1] + arr[i + 1][f - 2]);
			if (i - 1 >=0 && f + 2 <m)
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 1][f + 1] + arr[i - 1][f + 2]);
			if (i - 1 >=0 && f - 2 >= 0)
				max_ = max(max_, arr[i][f] + arr[i - 1][f] + arr[i - 1][f - 1] + arr[i - 1][f - 2]);
			// ㅁ
			// ㅁㅁ
			//   ㅁ
			if (i + 2 < n && f + 1 < m)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 1][f + 1] + arr[i + 2][f + 1]);
			if (i + 2 < n && f - 1 >= 0)
				max_ = max(max_, arr[i][f] + arr[i + 1][f] + arr[i + 1][f - 1] + arr[i + 2][f - 1]);
			// ㅁㅁ
			//   ㅁㅁ
			if (i + 1 < n && f + 2 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i + 1][f + 1] + arr[i + 1][f + 2]);
			if (i + 1 < n && f - 2 >= 0)
				max_ = max(max_, arr[i][f] + arr[i][f - 1] + arr[i + 1][f - 1] + arr[i + 1][f - 2]);
			// ㅁㅁㅁ
			//   ㅁ
			if (i + 1 < n && f + 2 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i][f + 2] + arr[i + 1][f + 1]);
			if (i - 1 >= 0 && f + 2 < m)
				max_ = max(max_, arr[i][f] + arr[i][f + 1] + arr[i][f + 2] + arr[i - 1][f + 1]);
			// ㅁ
			// ㅁㅁ
			// ㅁ
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