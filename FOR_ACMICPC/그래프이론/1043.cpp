#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
using ll = long long;
int tr[51];
vector<int>pt[51]; // 파티 -> ㅅ
vector<int>ps[51]; // ㅅ -> 파티
bool yestr[51] = { 0 }; // 진실파티
bool chk[51] = { 0 }; // 이미 호출한 사람인지 확인
int n, p, tru;
void jud(int truth) {
	// truth(party)의 사람들을 호출
	for (int i = 0; i < pt[truth].size(); i++) {
		if (chk[pt[truth][i]]) continue;
		chk[pt[truth][i]] = 1;
		// pt[truth][i]의 party를 true처리
		for (int f = 0; f < ps[pt[truth][i]].size(); f++) {
			if (yestr[ps[pt[truth][i]][f]]) continue;
			yestr[ps[pt[truth][i]][f]] = 1;
			// pt[truth][i]의 party의 남은 사람들을 호출
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
	// tru가 있는 party를 호출
	for (int i = 0; i < tru; i++) {
		if (chk[tr[i]]) continue;
		chk[tr[i]] = 1;
		for (int f = 0; f < ps[tr[i]].size(); f++) {
			if (yestr[ps[tr[i]][f]]) continue; // 진실체크 o
			yestr[ps[tr[i]][f]] = 1;
			jud(ps[tr[i]][f]);
		}
	}
	cout << p - accumulate(yestr, yestr + p, 0);
}