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
//�������� �˰���
//���ϴ� ���� �󸶳� �����ϴ��� ã�� ��, �ִ밪�� ã�� ��.
// <=���������� ���� �����ϱ� ���� ���� ������ �������� ���� �� �ִ�.
void twopointer(int target) {
	int i = 0, f = 0; //Initial i�� �ڵ������ ������ f�� �ռ����� ������
	int cur_sum = arr[0];

	while (f <= N - 1) {
		if (cur_sum == target) {
			counter++; //�ϴ� ��ǥ�հ� ��ġ�ϸ� count++
			if (i == f) {	// �ٵ� �յ� �����͵� ���� ? f����&�ش�迭��+
				cur_sum += arr[++f];
				continue;
			}
			else {
				cur_sum -= arr[i++]; // �յ� �����Ͱ� ������ �ƴϸ� �� �ڵ������ ������ �մ���
				continue;
			}
		}
		else if (cur_sum > target)
			cur_sum -= arr[i++]; //�����;մ���
		else
			cur_sum += arr[++f]; //�̰� i==0f==0�� ���� ��
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