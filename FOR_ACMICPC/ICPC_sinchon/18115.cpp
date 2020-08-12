#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
using ll = long long;
vector<int>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	int tmp = n;
	int a;
	int top = 0, frt = 1, bk = n - 1;
	while (tmp--) {
		cin >> a;
		if (a == 1) {
			top = frt++;
		}
		else if (a == 2) {
			frt++;
		}
		else {
			bk--;
		}
	}

	
}