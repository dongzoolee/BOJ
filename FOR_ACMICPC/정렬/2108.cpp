#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first > p2.first;
}

int main(void) {
	int n;
	cin >> n;
	int* nums = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);

	sort(nums, nums + n);
	vector<pair<int, int> >v;

	int ss, mid, ch, range;
	ss = 0;

	for (int i = 0; i < n; i++) {
		ss += nums[i];
		if (v.empty()) {
			v.push_back({ 1,nums[i] });
		}
		else if (v.back().second == nums[i]) {
			v.back().first++;
		}
		else {
			v.push_back({ 1,nums[i] });
		}
	}
	sort(v.begin(), v.end(), comp);
	ch = v[0].first == v[1].first ? v[1].second : v[0].second;
	mid = nums[n / 2];
	int sskhpk = (int)ceil(((double)ss / n) - 0.5);
	range = nums[n - 1] - nums[0];
	cout << sskhpk << endl << mid << endl << ch << std::endl << range;
	return 0;
}