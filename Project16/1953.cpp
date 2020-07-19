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
vector<int> hate[102];
vector<int> blue;
vector<int> white;
bool checker[102] = { 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int person, input;
		cin >> person;
		for (int f = 0; f < person; f++) {
			cin >> input;
			hate[i].push_back(input);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (checker[i] == 0) {
			bool whitebool = 0;
			for (int f = 0; f < hate[i].size(); f++) if (find(white.begin(), white.end(), hate[i][f]) != white.end()) whitebool = 1;
			if (find(blue.begin(), blue.end(), i) != blue.end() || whitebool == 1) {
				blue.push_back(i);
				checker[i] = 1;
				for (int f = 0; f < hate[i].size(); f++) {
					int tmp = hate[i][f];
					if (checker[tmp] == 0) {
						white.push_back(tmp);
						checker[tmp] = 1;
					}
					for (int h = 0; h < hate[tmp].size(); h++) {
						if (checker[hate[tmp][h]] == 0) {
							blue.push_back(hate[tmp][h]);
							checker[hate[tmp][h]] = 1;
						}
					}
				}
			}
			else {
				white.push_back(i);
				checker[i] = 1;
				for (int f = 0; f < hate[i].size(); f++) {
					int tmp = hate[i][f];
					if (checker[tmp] == 0) {
						blue.push_back(tmp);
						checker[tmp] = 1;
					}
					for (int h = 0; h < hate[tmp].size(); h++) {
						if (checker[hate[tmp][h]] == 0) {
							white.push_back(hate[tmp][h]);
							checker[hate[tmp][h]] = 1;
						}
					}
				}
			}
		}
	}
	cout << blue.size() << '\n';
	for (int i = 0; i < blue.size(); i++)
		cout << blue[i] << " ";

	cout << '\n' << white.size() << '\n';
	for (int i = 0; i < white.size(); i++)
		cout << white[i] << " ";
}