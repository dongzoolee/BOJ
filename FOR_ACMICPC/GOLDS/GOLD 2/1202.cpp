#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
vector<pair<int, int>>v;
vector<pair<int, int>>mwei;
int bosuk[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(v.begin(), v.end(), greater<>());
	mwei.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> mwei[i].first; mwei[i].second = 1;
	}
	sort(mwei.begin(), mwei.end());
	int unq = unique(mwei.begin(), mwei.end()) - mwei.begin();
	for (int i = unq; i < mwei.size(); i++) {
		int lwd = lower_bound(mwei.begin(), mwei.begin() + unq, make_pair(mwei[i].first, 0)) - mwei.begin();
		// 왼쪽은 찾을 값, 오른쪽은 최솟값
		mwei[lwd].second++;
	}
	ll sum = 0;
	int idx, cnt = 0;
	for (int i = 0; i < n; i++) {
		idx = lower_bound(mwei.begin(), mwei.begin() + unq, make_pair(v[i].second, 0)) - mwei.begin();
		if (mwei[idx].second) {
			mwei[idx].second--;
			sum += v[i].first;
		}
		else {
			while (idx < unq - 1 && mwei[idx].second == 0) {
				mwei.erase(mwei.begin()+idx);
				unq--; 
			}
			if (mwei[idx].second) {
				mwei[idx].second--;
				sum += v[i].first;
			}
		}
	}
	cout << sum;
}