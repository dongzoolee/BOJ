#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
using ll = long long;
vector<int>v;
int arr[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	int tmp = n;
	int a;
	// idx
	int top = 1, frt = 2, bk = n, ccnt = n;
	for (int i = 0; i < tmp; i++) {
		cin >> a;
		if (a == 1) {
			arr[top] = n - i;
			top = frt++;
			ccnt--;
		}
		else if (a == 2 && ccnt >= 2) {
			arr[frt] = n - i;
			frt++;
			ccnt--;
		}
		else if (a == 3 && ccnt >= 2) {
			arr[bk] = n - i;
			bk--;
			ccnt--;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
}