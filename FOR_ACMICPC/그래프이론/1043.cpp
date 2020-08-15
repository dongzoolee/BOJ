#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
using ll = long long;
int tr[51];
vector<int>pt[51]; // ��Ƽ -> ��
vector<int>ps[51]; // �� -> ��Ƽ
bool yestr[51] = { 0 }; // ������Ƽ
bool chk[51] = { 0 }; // �̹� ȣ���� ������� Ȯ��
int n, p, tru;
void jud(int truth) {
	// truth(party)�� ������� ȣ��
	for (int i = 0; i < pt[truth].size(); i++) {
		if (chk[pt[truth][i]]) continue;
		chk[pt[truth][i]] = 1;
		// pt[truth][i]�� party�� trueó��
		for (int f = 0; f < ps[pt[truth][i]].size(); f++) {
			if (yestr[ps[pt[truth][i]][f]]) continue;
			yestr[ps[pt[truth][i]][f]] = 1;
			// pt[truth][i]�� party�� ���� ������� ȣ��
			jud(ps[pt[truth][i]][f]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> p;
	cin >> tru;
	for (int i = 0; i < tru; i++) { cin >> tr[i]; }
	int tmp, a;
	for (int i = 0; i < p; i++) {
		cin >> tmp;
		while (tmp--) {
			cin >> a;
			pt[i].push_back(a);
			ps[a].push_back(i);
		}
	}
	// tru�� �ִ� party�� ȣ��
	for (int i = 0; i < tru; i++) {
		if (chk[tr[i]]) continue;
		chk[tr[i]] = 1;
		for (int f = 0; f < ps[tr[i]].size(); f++) {
			if (yestr[ps[tr[i]][f]]) continue; // ����üũ o
			yestr[ps[tr[i]][f]] = 1;
			jud(ps[tr[i]][f]);
		}
	}
	cout << p - accumulate(yestr, yestr + p, 0);
}