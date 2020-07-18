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
int splt[8] = { 0 };
int arr[8][8] = { 0 }, n, m, max_ = 0, cctvcnt = 0;
vector<pair<int, pair<int, int>>>v;

void exec(int z, vector<vector<bool>>&chk, int* cnt) {
	int num = v[z].first;
	int idx = splt[z];
	int fst = v[z].second.first, scd = v[z].second.second;
	switch (num) {
	case 5: {
		// EAST
		for (int f = v[z].second.second + 1; f < m && arr[fst][f] != 6; f++)
			if (chk[fst][f] == 0 && arr[fst][f] == 0) {
				chk[fst][f] = 1;
				(*cnt)++;
			}
		// SOUTH
		for (int f = v[z].second.first + 1; f < n && arr[f][scd] != 6; f++)
			if (chk[f][scd] == 0 && arr[f][scd] == 0) {
				chk[f][scd] = 1;
				(*cnt)++;
			}
		// WEST
		for (int f = v[z].second.second - 1; f >= 0 && arr[fst][f] != 6; f--)
			if (chk[fst][f] == 0 && arr[fst][f] == 0) {
				chk[fst][f] = 1;
				(*cnt)++;
			}
		// NORTH
		for (int f = v[z].second.first - 1; f >= 0 && arr[f][scd] != 6; f--)
			if (chk[f][scd] == 0 && arr[f][scd] == 0) {
				chk[f][scd] = 1;
				(*cnt)++;
			}
	}
	case 4: {
		if (idx == 0) {
			// NORTH
			for (int f = v[z].second.first - 1; f >= 0 && arr[f][scd] != 6; f--)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
			// EAST
			for (int f = v[z].second.second + 1; f < m && arr[fst][f] != 6; f++)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
			// SOUTH
			for (int f = v[z].second.first + 1; f < n && arr[f][scd] != 6; f++)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 1) {
			// EAST
			for (int f = v[z].second.second + 1; f < m && arr[fst][f] != 6; f++)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
			// SOUTH
			for (int f = v[z].second.first + 1; f < n && arr[f][scd] != 6; f++)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
			// WEST
			for (int f = v[z].second.second - 1; f >= 0 && arr[fst][f] != 6; f--)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 2) {
			// SOUTH
			for (int f = v[z].second.first + 1; f < n && arr[f][scd] != 6; f++)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
			// WEST
			for (int f = v[z].second.second - 1; f >= 0 && arr[fst][f] != 6; f--)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
			// NORTH
			for (int f = v[z].second.first - 1; f >= 0 && arr[f][scd] != 6; f--)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 3) {
			// WEST
			for (int f = v[z].second.second - 1; f >= 0 && arr[fst][f] != 6; f--)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
			// NORTH
			for (int f = v[z].second.first - 1; f >= 0 && arr[f][scd] != 6; f--)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
			// EAST
			for (int f = v[z].second.second + 1; f < m && arr[fst][f] != 6; f++)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
		}
	}
	case 3: {
		if (idx == 0) {
			// EAST
			for (int f = v[z].second.second + 1; f < m && arr[fst][f] != 6; f++)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
			// SOUTH
			for (int f = v[z].second.first + 1; f < n && arr[f][scd] != 6; f++)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 1) {
			// SOUTH
			for (int f = v[z].second.first + 1; f < n && arr[f][scd] != 6; f++)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
			// WEST
			for (int f = v[z].second.second - 1; f >= 0 && arr[fst][f] != 6; f--)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 2) {
			// WEST
			for (int f = v[z].second.second - 1; f >= 0 && arr[fst][f] != 6; f--)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
			// NORTH
			for (int f = v[z].second.first - 1; f >= 0 && arr[f][scd] != 6; f--)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 3) {
			// NORTH
			for (int f = v[z].second.first - 1; f >= 0 && arr[f][scd] != 6; f--)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
			// EAST
			for (int f = v[z].second.second + 1; f < m && arr[fst][f] != 6; f++)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
		}
	}
	case 2: {
		if (idx == 0) {
			// EAST
			for (int f = v[z].second.second + 1; f < m && arr[fst][f] != 6; f++)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
			// WEST
			for (int f = v[z].second.second - 1; f >= 0 && arr[fst][f] != 6; f--)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 1) {
			// SOUTH
			for (int f = v[z].second.first + 1; f < n && arr[f][scd] != 6; f++)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
			// NORTH
			for (int f = v[z].second.first - 1; f >= 0 && arr[f][scd] != 6; f--)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
		}
	}
	case 1: {
		if (idx == 0) {
			// EAST
			for (int f = v[z].second.second + 1; f < m && arr[fst][f] != 6; f++)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 1) {
			// SOUTH
			for (int f = v[z].second.first + 1; f < n && arr[f][scd] != 6; f++)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 2) {
			// WEST
			for (int f = v[z].second.second - 1; f >= 0 && arr[fst][f] != 6; f--)
				if (chk[fst][f] == 0 && arr[fst][f] == 0) {
					chk[fst][f] = 1;
					(*cnt)++;
				}
		}
		else if (idx == 3) {
			// NORTH
			for (int f = v[z].second.first - 1; f >= 0 && arr[f][scd] != 6; f--)
				if (chk[f][scd] == 0 && arr[f][scd] == 0) {
					chk[f][scd] = 1;
					(*cnt)++;
				}
		}
	}
	}
}

void split(int idx, vector<vector<bool>>chk, int cnt) {
	if (idx == cctvcnt) {
		max_ = max(max_, cnt); return;
	}
	int tmpcnt;
	vector<vector<bool>>tmp;

	for (int i = 0; i < 4; i++) {
		if (i == 0) { tmp = chk; tmpcnt = cnt; }
		splt[idx] = i;
		exec(idx, chk, &cnt);
		split(idx + 1, chk, cnt);
		chk = tmp;
		cnt = tmpcnt;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int zero_cnt = 0;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			cin >> arr[i][f];
			if (arr[i][f] != 0 && arr[i][f] != 6) {
				v.push_back({ arr[i][f], { i,f } });
				cctvcnt++;
			}
			else if (arr[i][f] == 0)
				zero_cnt++;
		}
	vector<vector<bool>>chk;
	chk.assign(8, vector<bool>(8, 0));
	split(0, chk, 0);

	cout << zero_cnt - max_;
}