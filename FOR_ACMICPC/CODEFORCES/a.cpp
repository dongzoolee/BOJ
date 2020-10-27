#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
#include <map>
#include <iomanip>
using namespace std;
using ll = long long;
int idx1 = 0, idx2 = 0, score = 0;
string str;
vector<string>idex;
vector<string>stop;
map<string, int>m;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string tmp;

	getline(cin, tmp);
	int bef = 0;
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == ';') {
			stop.push_back(tmp.substr(bef, i - bef));
			bef = i + 1;
		}
	}
	stop.push_back(tmp.substr(bef, tmp.length() - bef));
	sort(stop.begin(), stop.end());

	getline(cin, tmp);
	bef = 0;
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == ';') {
			idex.push_back(tmp.substr(bef, i - bef));
			bef = i + 1;
		}
	}
	idex.push_back(tmp.substr(bef, tmp.length() - bef));
	sort(idex.begin(), idex.end());

	while (getline(cin, tmp)) {
		str += tmp;
		str += ' ';
	}
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ',' || str[i] == '.' || str[i] == '?' || str[i] == '!') {
			str.replace(i, 1, "");
			i--;
		}
		else if (i + 1 < str.length() && str[i] == ' ' && str[i + 1] == ' ') {
			str.replace(i, 2, " ");
			i--;
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
	}
	int ans = 0, total = 0;


	int id1 = str.find("<title>");
	int id2 = str.find("</title>");
	int tt = id1 + 7, cnt = 0;
	bool chk = 1;
	for (int i = id1 + 7; i < id2; i++) {
		if (str[i] == '<') {
			if (chk) {
				if (i - tt > 3) {
					string tp = str.substr(tt, i - tt);
					if (!binary_search(stop.begin(), stop.end(), tp))
						total++;
					if (binary_search(idex.begin(), idex.end(), tp))
						m[tp] += 5;
				}
			}
			chk = 0;
		}
		else if (str[i] == '>') {
			chk = 1;
			tt = i + 1;
		}
		else if (chk && str[i] == ' ') {
			if (i - tt > 3) {
				string tp = str.substr(tt, i - tt);
				if (!binary_search(stop.begin(), stop.end(), tp))
					total++;
				if (binary_search(idex.begin(), idex.end(), tp))
					m[tp] += 5;
			}
			tt = i + 1;
		}
	}
	string tp = str.substr(tt, id2 - tt);
	if (id2 - tt > 3) {
		if (!binary_search(stop.begin(), stop.end(), tp))
			total++;
		if (binary_search(idex.begin(), idex.end(), tp))
			m[tp] += 5;
	}
	ans += cnt * 5;

	int id3 = str.find("<abstract>");
	int id4 = str.find("</abstract>");
	tt = id3 + 10, cnt = 0;
	chk = 1;
	for (int i = id3 + 10; i < id4; i++) {
		if (str[i] == '<') {
			if (chk) {
				if (i - tt > 3) {
					string tp = str.substr(tt, i - tt);
					if (!binary_search(stop.begin(), stop.end(), tp))
						total++;
					if (binary_search(idex.begin(), idex.end(), tp))
						m[tp] += 3;
				}
			}
			chk = 0;
		}
		else if (str[i] == '>') {
			chk = 1;
			tt = i + 1;
		}
		else if (chk && str[i] == ' ') {
			if (i - tt > 3) {
				string tp = str.substr(tt, i - tt);
				if (!binary_search(stop.begin(), stop.end(), tp))
					total++;
				if (binary_search(idex.begin(), idex.end(), tp))
					m[tp] += 3;
			}
			tt = i + 1;
		}
	}
	tp = str.substr(tt, id4 - tt);
	if (id4 - tt > 3) {
		if (!binary_search(stop.begin(), stop.end(), tp))
			total++;
		if (binary_search(idex.begin(), idex.end(), tp))
			m[tp] += 3;
	}
	ans += 3 * cnt;

	int id5 = str.find("<body>");
	int id6 = str.find("</body>");
	tt = id5 + 6, cnt = 0;
	chk = 1;
	for (int i = id5 + 6; i < id6; i++) {
		if (str[i] == '<') {
			if (chk) {
				if (i - tt > 3) {
					string tp = str.substr(tt, i - tt);
					if (!binary_search(stop.begin(), stop.end(), tp))
						total++;
					if (binary_search(idex.begin(), idex.end(), tp))
						m[tp]++;
				}
			}
			chk = 0;
		}
		else if (str[i] == '>') {
			chk = 1;
			tt = i + 1;
		}
		else if (chk && str[i] == ' ') {
			if (i - tt > 3) {
				string tp = str.substr(tt, i - tt);
				if (!binary_search(stop.begin(), stop.end(), tp))
					total++;
				if (binary_search(idex.begin(), idex.end(), tp))
					m[tp]++;
			}
			tt = i + 1;
		}
	}
	tp = str.substr(tt, id6 - tt);
	if (id6 - tt > 3) {
		if (!binary_search(stop.begin(), stop.end(), tp))
			total++;
		if (binary_search(idex.begin(), idex.end(), tp))
			m[tp]++;
	}
	ans += cnt;
	vector<pair<string, int>>v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.second > b.second;
	});
	int mx = v[0].second;
	for (int i = 1; i < v.size(); i++)
		if (mx != v[i].second) {
			cnt++;
			mx = v[i].second;
			if (cnt == 2)
				break;
		}
	cout << fixed << setprecision(10);
	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		if (mx > v[i].second) break;
		if(v[i].second)
			cout << v[i].first << ": " << (double)v[i].second / total * 100 << '\n';
	}
}