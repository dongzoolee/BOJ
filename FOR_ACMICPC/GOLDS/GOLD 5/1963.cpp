#include <iostream>
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
using ll = long long;
int inp1, inp2, tenp[5] = { 1, 10,100,1000,10000 }, frt_num[4], min_ = 0, cnt = 0;
bool pr[10001] = { 0 }; // 소수 아닌 것만 1

void bfs_judge() {
	queue<int>q;
	bool chk[10001] = { 0 };
	min_ = cnt = 0;
	chk[inp1] = 1;
	q.push(inp1);

		while (!q.empty()) {
			int qsize = q.size();
			for (int h = 0; h < qsize; h++) {
				int frt = q.front();

				int temp = frt;
				for (int f = 0; f < 4; f++) { // frt의 자리수 저장용
					frt_num[f] = temp % 10;
					temp /= 10;
				}

				if (frt == inp2) min_ = cnt;
				q.pop();
				for (int f = 0; f < 4; f++) // f == 0이 맨 뒷자리 f==3이 맨 앞자리
					for (int i = 0; i < 10; i++) {
						// JUMP condition
						if (f == 3)  // 첫번째자리 => 0오지않음
							if (i == 0) continue;
						if (frt_num[f] == i) continue; // 자리수가 i와 일치하면 넘어가기

						int changed = frt - tenp[f] * frt_num[f] + i * tenp[f];
						if (pr[changed] == 0 && chk[changed] == 0) {
							chk[changed] = 1;
							q.push(changed);
						}
					}
			}
			cnt++; // bfs의 층 저장
		}
}

void prime() {
	for (int i = 2; i < 10000; i++)
		for (int f = i + i; f < 10000; f += i)
			if (f >= 1000)
				pr[f] = 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prime();
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> inp1 >> inp2;

		if (inp1 == inp2) { cout << 0 << "\n"; continue; }
		bfs_judge();
		if (min_ == 0) //  최솟값 못찾음
			cout << "Impossible\n";
		else
			cout << min_ << "\n";
	}
}