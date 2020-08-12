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
#include <tuple>
#include<numeric>
using namespace std;
using ll = long long;
int in[100000];
int post[100000];
int child[100001][2];
void preorder(int idx) {
	//위
		cout << idx << ' ';
	//L
	if (child[idx][0] != -1)
		preorder(child[idx][0]);
	//R
	if (child[idx][1] != -1)
		preorder(child[idx][1]);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> in[i];
	for (int i = 0; i < n; i++)	cin >> post[i];
	vector<int>v;
	for (int i = 0; i < 100001; i++) fill(child[i], child[i] + 2, -1);
	int pdx = 0;
	for (int i = 0; i < n; i++) {
		// L이 있다면...
		if (in[i] == post[pdx]) {
			// idx조심
			// 위가 없을린 없으니까
			child[in[i + 1]][0] = in[i];
			// R이 있다면
			if (in[i + 2] == post[pdx + 1]) {
				child[in[i + 1]][1] = in[i + 2];
				i += 2;
				pdx += 3;
			}
			else {
				// R이 없다면
				i++;
				pdx += 2;
			}
		}
		else {
			// L이없다면
			// R은?
			if (in[i + 1] == post[pdx]) {
				// R있음
				child[in[i]][1] = post[pdx];
				i++;
				pdx += 2;
			}
			else {
				// R없음
				pdx++;
			}
		}
	}
	int root = post[n - 1];
	preorder(root);
}