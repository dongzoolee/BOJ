#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int arr[500000][2] = { 0 }, ar[500001], rem[500001];

int binary(int arr[], int target, int length) {
	int low = 0;
	int high = length - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] == target)
			return 1; //찾음
		else if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0; //못찾음
}

int main() {
	long long n, a = 0, sum = 0;
	cin >> n;

	for (int i = 1; i < n; i++) {
		long long temp = (long long)pow(i, 2) % n;
		if (arr[temp][0] == 0)
			ar[a++] = temp;
		arr[temp][0]++;
	}
	sort(ar, ar + a);

	for (int i = 1; i < n; i++)
		rem[i] = ((long long)pow(i, 2) % n);

	for (int i = 1; i < n; i++)
		for (int f = i; f < n; f++)
			if(binary(ar, rem[i]+rem[f], a))
				arr[rem[i] + rem[f]][1]++;

	for (int i = 0; i < a; i++)
		sum += (arr[ar[i]][0] * arr[ar[i]][1]);

	cout << sum;
}