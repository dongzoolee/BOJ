#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int arr[11];
int res[11];
int vac[11];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) vac[i] = 1;

	for (int i = 1; i <= n; i++) {
		for (int f = 1; f <= n; f++) {
			if (arr[i] && vac[f]) {
				arr[i] -= vac[f];
			}
			else if(vac[f]){
				vac[f]--;
				res[f] = i;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}