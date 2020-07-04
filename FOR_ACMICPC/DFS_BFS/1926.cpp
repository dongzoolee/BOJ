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
	int dy[4] = { 0,1,0,-1 };	// 동쪽 북쪽 서쪽 남쪽
	bool checker[501][501] = { 0 }; // 방문처리용 bool
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];

	// BFS는 언제적용 ? 인접대상에 대해 끝까지 뻗어나갈 때
	// 인접대상은 전체 상자를 돌면서 1부터 끝까지 확인해봐야함
	// 방문처리된 곳은 돌지 않는다. continue

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) { // arr가 1인 곳에서만 BFS를 진행한다 = 큐를 만든다.
			// 이미 방문했거나 애초에 탐색지역이 아닌경우
			if (checker[i][f] == 1 || arr[i][f] == 0) continue;
			// ELSE
			total++; // 박스갯수처리
			width = 1; // 넓이 1로 해주고
			checker[i][f] = 1;	//	방문처리
			queue<pair<int, int>> q;	//	좌표를 관리해야하므로 pair처리
			q.push({ i,f });	//박스시작위치(현재위치) push
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int h = 0; h < 4; h++) { // 내 발상은 아닌데 걍 +1 -1 좌표를 배열에 미리 넣어놓고 for문 돌리기
					int cur_x = x + dx[h], cur_y = y + dy[h];
					if (arr[cur_x][cur_y] == 0 || checker[cur_x][cur_y] == 1) continue;
					if (cur_x < 0 || cur_y < 0 || cur_x >= n || cur_y >= m) continue;
					width++;
					checker[cur_x][cur_y] = 1;
					q.push({ cur_x,cur_y });
				}
			} // end of while
			//	큐가 끝나면 max_width 확인
			max_width = max(max_width, width);
		}
	cout << total << '\n' << max_width;

}