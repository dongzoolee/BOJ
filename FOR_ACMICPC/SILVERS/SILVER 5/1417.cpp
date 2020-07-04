#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, candidate[1002], sum_expt_1 = 0, sum = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> candidate[i];
		if (i != 1)
			sum_expt_1 += candidate[i];
	}
	sort(candidate + 2, candidate + N + 1);
	for (int i = 2; i <= N; i++)
	while (candidate[i] >= candidate[1]) {
		sum += (candidate[i] + candidate[1]) / 2 - candidate[1] + 1;
		candidate[1]+= (candidate[i] + candidate[1]) / 2 - candidate[1] + 1;
	}
	cout << sum;
}