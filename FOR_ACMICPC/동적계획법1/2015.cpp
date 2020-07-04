#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
long long arr[200001], counter = 0;

int main() {
	long long n, k;
	cin >> n >> k;
	for (long long i = 0; i < n; i++)
		cin >> arr[i];

	//투포인터
	long long a = 0, b = 0, cur_sum = arr[0];
	while (b != n-1) {
		if (cur_sum == k) {
			cur_sum -= arr[a++];
			cur_sum += arr[++b];
			counter++;
		}
		else if (cur_sum > k && a!=b) {
			cur_sum -= arr[a++];
		}
		else if(cur_sum <k && a!=b){
			cur_sum += arr[++b];
		}
		else {
			cur_sum += arr[++b];
		}
	}
	if (cur_sum == k)
		counter++;
	//a올때까지 기다려주셈
	while (a != n) {
		cur_sum -= arr[a++];
		if (cur_sum == k)
			counter++;
	}
	cout << counter;
}