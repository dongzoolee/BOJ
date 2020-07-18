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
#include <ctime>
using namespace std;
using ll = long long;
int arr[8][8] = { 0 }, n, m, max_ = 0, cctvcnt = 0;
vector<pair<int, int>>v[6];
int sum = 0;

int exe(vector<pair<pair<int, int>, int>>vec, vector<vector<bool>>chk) {
	int cnt = 0;
	for (int z = 0; z < vec.size(); z++) {
		int num = vec[z].first.first, i = vec[z].first.second;
		int idx = vec[z].second;
		int fst = v[num][i].first, scd = v[num][i].second;
		if (num == 5) {
			// EAST
			for (int f = v[5][i].second + 1; f < m && arr[fst][f] != 6; f++)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					cnt++;
				}
			// SOUTH
			for (int f = v[5][i].first + 1; f < n && arr[f][scd] != 6; f++)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					cnt++;
				}
			// WEST
			for (int i = 0; i < v[5].size(); i++)
				for (int f = v[5][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			// NORTH
			for (int i = 0; i < v[5].size(); i++)
				for (int f = v[5][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
		}
		if (num == 4) {
			if (idx == 0) {
				// NORTH
				for (int f = v[4][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
				// EAST
				for (int f = v[4][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
				// SOUTH
				for (int f = v[4][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// EAST
				for (int f = v[4][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
				// SOUTH
				for (int f = v[4][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
				// WEST
				for (int f = v[4][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 2) {
				// SOUTH
				for (int f = v[4][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
				// WEST
				for (int f = v[4][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
				// NORTH
				for (int f = v[4][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 3) {
				// WEST
				for (int f = v[4][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
				// NORTH
				for (int f = v[4][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
				// EAST
				for (int f = v[4][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
		}
		if (num == 3) {
			if (idx == 0) {
				// EAST
				for (int f = v[3][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
				// SOUTH
				for (int f = v[3][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// SOUTH
				for (int f = v[3][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
				// WEST
				for (int f = v[3][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 2) {
				// WEST
				for (int f = v[3][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
				// NORTH
				for (int f = v[3][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 3) {
				// NORTH
				for (int f = v[3][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
				// EAST
				for (int f = v[3][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
		}
		if (num == 2) {
			if (idx == 0) {
				// EAST
				for (int f = v[2][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
				// WEST
				for (int f = v[2][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// SOUTH
				for (int f = v[2][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
				// NORTH
				for (int f = v[2][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
		}
		if (num == 1) {
			if (idx == 0) {
				// EAST
				for (int f = v[1][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// SOUTH
				for (int f = v[1][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 2) {
				// WEST
				for (int f = v[1][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0 && arr[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 3) {
				// NORTH
				for (int f = v[1][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0 && arr[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
		}
	}
	return cnt;
}
void jj(vector<pair<pair<int, int>, int>> vec, int idx, int num, vector<vector<bool>>chk) {
	if (vec.size() == cctvcnt) { max_ = max(max_, exe(vec, chk));  return; }
	if (num > 5) return;
	if (idx >= v[num].size()) return jj(vec, 0, num + 1, chk);
	if (v[num].size() == 0) return jj(vec, 0, num + 1, chk);

	if (num == 5) {
		vec.push_back({ {num,idx }, 0 });
		jj(vec, idx + 1, num, chk);
		vec.pop_back();
	}
	else if (num == 2) {
		for (int f = 0; f < 2; f++) {
			vec.push_back({ {num,idx }, f });
			jj(vec, idx + 1, num, chk);
			vec.pop_back();
		}
	}
	else if(num == 1)
		for (int f = 0; f < 4; f++) {
			vec.push_back({ {num,idx }, f });
			jj(vec, idx + 1, num, chk);
			vec.pop_back();
		}
	else
		for (int f = 0; f < 4; f++) {
			vec.push_back({ {num,idx }, f });
			jj(vec, idx + 1, num, chk);
			vec.pop_back();
		}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t startTime = clock();
	cin >> n >> m;
	int zero_cnt = 0;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			cin >> arr[i][f];
			if (arr[i][f] != 0 && arr[i][f] != 6) {
				v[arr[i][f]].push_back({ i,f });
				cctvcnt++;
			}
			else if (arr[i][f] == 0)
				zero_cnt++;
		}

	vector<pair<pair<int, int>, int>>vc;
	vector<vector<bool>>chk;
	chk.assign(8, vector<bool>(8, 0));
	jj(vc, 0, 1, chk);

	cout << zero_cnt - max_;
	clock_t endTime = clock();
	cout << "\n걸린시간 : " << endTime - startTime <<"ms";
}