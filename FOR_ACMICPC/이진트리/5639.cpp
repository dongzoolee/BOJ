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
	//st는 무조건 루트
	if (st > end) return; // 왜지? st == end는 무조건 오른쪽 노드이기 때문
	// sub tree를 잡는 과정
	int mid = end;
	while (v[mid] > v[st]) mid--;
	// 그러므로 mid-1이 아니라 mid임
	conq(st + 1, mid);
	conq(mid + 1, end);
	cout << v[st] << '\n';
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int a;
	while (!cin.eof()) { // 쓰지말자 ㅡㅡBOJ 테케 뒤에 개행한다 ㅡㅡ
		cin >> a;
		v.push_back(a);
	}
	conq(0, v.size() - 1);
}