#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
using ll = long long;
vector<char>ch[8];
vector<int>alp[26];
void judge(int idx) {

}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int idx = 7;
		for (int f = str.length() - 1; f >= 0; f--) {
			ch[idx].push_back(str[f]);
			alp[str[f] - 'A'].push_back(idx--);
		}
	}
	for (int i = 0; i < 8; i++) {
		if (!ch[i].size()) continue;

		// �ڸ��� ���� //
		for (int f = 0; f < ch[i].size(); f++) {
			// �ش� �ڸ��� ���ĺ��� ��� ����
			for (int h = 0; h < ch[i][f]].size(); h++) {
				judge(alp[ch[i][f]][h]);
			}
		}
	}
}