#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
vector<int>v;
void conq(int st, int end) {
	//st�� ������ ��Ʈ
	if (st > end) return; // ����? st == end�� ������ ������ ����̱� ����
	// sub tree�� ��� ����
	int mid = end;
	while (v[mid] > v[st]) mid--;
	// �׷��Ƿ� mid-1�� �ƴ϶� mid��
	conq(st + 1, mid);
	conq(mid + 1, end);
	cout << v[st] << '\n';
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int a;
	while (!cin.eof()) { // �������� �Ѥ�BOJ ���� �ڿ� �����Ѵ� �Ѥ�
		cin >> a;
		v.push_back(a);
	}
	conq(0, v.size() - 1);
}