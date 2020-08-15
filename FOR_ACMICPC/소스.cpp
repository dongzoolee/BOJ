#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int cost[3], wei[3];
vector<double>ga;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n = 3;
	ga.resize(3);
	while (n--) {
		cin >> cost[n] >> wei[n];
		if (cost[n] * 10 >= 5000) {
			ga[n] = double(wei[n] * 10) / (cost[n] * 10 - 500);
		}
		else {
			ga[n] = double(wei[n] * 10) / (cost[n] * 10);
		}
	}
	double mx = max_element(ga.begin(), ga.end()) - ga.begin();
	if (mx == 0)
		cout << 'U';
	if (mx == 1)
		cout << 'N';
	if (mx == 2)
		cout << 'S';

}