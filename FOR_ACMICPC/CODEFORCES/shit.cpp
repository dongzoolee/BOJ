#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int w, gicho, t;
	int d, eat, use;
	cin >> w >> gicho >> t;
	cin >> d >> eat >> use;
	int di = d;
	int wi = w;
	int gichoi = gicho;
	while (di--) {
		wi += (eat - (gicho + use));
	}
	int toadd;
	while (d--) {
		w += (eat - (gicho + use));
		if (abs(eat - (gicho + use)) > t) {

			gicho += floor((double)(eat - (gicho + use)) / 2);
		}
	}
	if (wi > 0 && gichoi > 0)
		cout << wi << ' ' << gichoi;
	else
		cout << "Danger Diet";

	cout << '\n';

	if (w > 0 && gicho > 0) {
		cout << w << ' ' << gicho << ' ';
		if (gichoi - gicho > 0)
			cout << "YOYO";
		else
			cout << "NO";
	}
	else
		cout << "Danger Diet";
}