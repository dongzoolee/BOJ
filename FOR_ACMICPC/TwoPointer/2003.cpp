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
int N, arr[10000], counter = 0;
//투포인터 알고리즘
//원하는 값이 얼마나 등장하는지 찾을 때, 최대값을 찾을 때.
// <=이전까지의 합이 있으니까 다음 수를 더할지 무시할지 정할 수 있다.
void twopointer(int target) {
	int i = 0, f = 0; //Initial i는 뒤따라오는 포인터 f는 앞서가는 포인터
	int cur_sum = arr[0];

	while (f <= N - 1) {
		if (cur_sum == target) {
			counter++; //일단 목표합과 일치하면 count++
			if (i == f) {	// 근데 앞뒤 포인터도 같다 ? f증가&해당배열값+
				cur_sum += arr[++f];
				continue;
			}
			else {
				cur_sum -= arr[i++]; // 앞뒤 포인터가 같은게 아니면 걍 뒤따라오는 포인터 앞당기기
				continue;
			}
		}
		else if (cur_sum > target)
			cur_sum -= arr[i++]; //포인터앞당기기
		else
			cur_sum += arr[++f]; //이건 i==0f==0을 위한 식
	}
}

int main() {
	int _sum;
	cin >> N >> _sum;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	twopointer(_sum);
	cout << counter;

}