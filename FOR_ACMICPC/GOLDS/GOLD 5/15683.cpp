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
			if (idx == 0) {
				// EAST
				for (int f = v[5][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// SOUTH
				for (int f = v[5][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 2) {
				// WEST
				for (int i = 0; i < v[5].size(); i++) {
					fst = v[5][i].first;
					for (int f = v[5][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
						if (chk[fst][f] == 0) {
							chk[fst][f] = 1;
							cnt++;
						}
				}
			}
			if (idx == 3) {
				// NORTH
				for (int i = 0; i < v[5].size(); i++) {
					scd = v[5][i].second;
					for (int f = v[5][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
						if (chk[f][scd] == 0) {
							chk[f][scd] = 1;
							cnt++;
						}
				}
			}
		}
		if (num == 4) {
			if (idx == 0) {
				// EAST
				for (int f = v[4][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// SOUTH
				for (int f = v[4][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 2) {
				// WEST
				for (int f = v[4][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 3) {
				// NORTH
				int scd = v[4][i].second;
				for (int f = v[4][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
		}
		if (num == 3) {
			if (idx == 0) {
				// EAST
				for (int f = v[3][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// SOUTH
				for (int f = v[3][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 2) {
				// WEST
				for (int f = v[3][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 3) {
				// NORTH
				for (int f = v[3][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
		}
		if (num == 2) {
			if (idx == 0) {
				// EAST
				for (int f = v[2][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// SOUTH
				for (int f = v[2][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 2) {
				// WEST
				for (int f = v[2][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 3) {
				// NORTH
				for (int f = v[2][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
		}
		if (num == 1) {
			if (idx == 0) {
				// EAST
				for (int f = v[1][i].second + 1; f < m && arr[fst][f] != 6; f++)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 1) {
				// SOUTH
				for (int f = v[1][i].first + 1; f < n && arr[f][scd] != 6; f++)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
			if (idx == 2) {
				// WEST
				for (int f = v[1][i].second - 1; f >= 0 && arr[fst][f] != 6; f--)
					if (chk[fst][f] == 0) {
						chk[fst][f] = 1;
						cnt++;
					}
			}
			if (idx == 3) {
				// NORTH
				for (int f = v[1][i].first - 1; f >= 0 && arr[f][scd] != 6; f--)
					if (chk[f][scd] == 0) {
						chk[f][scd] = 1;
						cnt++;
					}
			}
		}
	}
	return cnt;
}
void jj(vector<pair<pair<int, int>, int>>vec, int num, vector<vector<bool>>chk) {
	if (vec.size() == cctvcnt) { max_ = max(max_, exe(vec, chk));  return; }
	if (num > n) return;

	for (int h = 0; h < v[num].size(); h++) {
		for (int f = 0; f < 4; f++) {
			vec.push_back({ {num,h }, f });
			jj(vec, num + 1, chk);
			vec.pop_back();
		}
	}
}/*
void judge(int num) {
	int fst, scd;
	if (num == 5) {
		int cnt = 0;
		sum += cnt;
	}
	if (num == 4) {
		for (int i = 0; i < v[4].size(); i++) {
			vector<pair<int, int>>vec;
			int dir[4] = { 0 };
			fst = v[4][i].first, scd = v[4][i].second;

			int max_ = 0;
			max_ = max(max_, dir[0] + dir[1] + dir[2]);
			max_ = max(max_, dir[1] + dir[2] + dir[3]);
			max_ = max(max_, dir[2] + dir[3] + dir[0]);
			max_ = max(max_, dir[3] + dir[0] + dir[1]);
			sum += max_;

			for (int i = 0; i < vec.size(); i++)
		}
	}
	if (num == 3) {
		for (int i = 0; i < v[3].size(); i++) {
			int dir[4] = { 0 };
			fst = v[3][i].first, scd = v[3][i].second;

			int max_ = 0;
			max_ = max(max_, dir[0] + dir[1]);
			max_ = max(max_, dir[1] + dir[2]);
			max_ = max(max_, dir[2] + dir[3]);
			max_ = max(max_, dir[3] + dir[0]);

			sum += max_;
		}
	}
	if (num == 2) {
		for (int i = 0; i < v[2].size(); i++) {
			int dir[4] = { 0 };
			fst = v[2][i].first, scd = v[2][i].second;

			int max_ = 0;
			max_ = max(max_, dir[0] + dir[2]);
			max_ = max(max_, dir[1] + dir[3]);

			sum += max_;
		}
	}
	if (num == 1) {
		for (int i = 0; i < v[1].size(); i++) {
			int dir[4] = { 0 };
			fst = v[1][i].first, scd = v[1][i].second;

			int max_ = 0;
			max_ = max(max_, dir[0]);
			max_ = max(max_, dir[1]);
			max_ = max(max_, dir[2]);
			max_ = max(max_, dir[3]);

			sum += max_;
		}
	}
}*/
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

		vector<pair<pair<int, int>, int>>v;
		//bool chk[8][8];
		vector<vector<bool>>chk;
		chk.assign(8, vector<bool>(8, 0));
		jj(v, 1, chk);

	cout << zero_cnt - max_;
}
