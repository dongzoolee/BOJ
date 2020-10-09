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
ll inp[100000];
int a;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (cin >> a) {
		if (a == 0) return 0;
		int last = 0;
		// 스택에 스택idx & 높이 넣을거임
		stack <pair<int, ll>>st;
		for (int f = 0; f < a; f++)
			cin >> inp[f];

		// 제일 큰 직사각형 넓이 담을 곳
		ll max_ = 0;
		for (int i = 0; i < a; i++) {

			// 제일 처음에는 일단 넣어줌
			if (!st.size()) {
				st.push({ i, inp[i] });
			}
			else if (st.top().second <= inp[i]) {
				// 지금 보고 있는 건물보다 stack top에 있는 놈이 작으면 계속 push
				st.push({ i, inp[i] });
			}
			else {
				// stack top 건물 크기보다 현재 건물이 작으면
				while (st.size() && st.top().second > inp[i]) {
					// 나보다 작은 건물 나올 때 까지 계속 pop 해줄건데
					max_ = max(max_, (i - st.top().first) * st.top().second);
					// pop한 건물들은 전부 없는 존재로 치는 거임 이제부터
					// = 건물 인덱스를 i가 아니라 (i - 내가 지운 건물 수)로 할거임 (== last)
					last = st.top().first;
					// 그래서 그냥 top의 idx를 저장해서 내꺼로 만들거임
					// = 그래서 건물 크기 세는 것도 문제가 안됨
					// 왜냐면 앞으로 i는 내 건물 원래 idx에서부터 커질 꺼고
					// 나는 (i-지운 건물 수)를 새로운 idx로 갖기 때문에
					// 앞으로의 건물 idx - 나의 새로운 idx
					// = 앞으로의 건물 idx - (내 원래 i - 지운건물수)
					// 앞으로의 건물 idx - 내 원래 i 는 내 앞에 있는, 나보다 크거나 같은 건물 수
					// +지운건물수는 내 뒤의 나보다 크거나 같은 건물 수 로 계산되어
					// 정상적으로 수가 계산됨.
					st.pop();
				}
				st.push({ last, inp[i] });
			}
		}
		 
		// stack에 남은 것들 후 처리 //
		// n번째 건물(실제로는 없는 건물)이 높이 0인 건물이라고 생각하여
		// stack에 있는 건물들이 다 0보다 높은 건물들이 돼버림
		// = 다 빼줌
		while (st.size()) {
			max_ = max(max_, (a - st.top().first) * st.top().second);
			st.pop();
		}
		cout << max_ << '\n';
	}
}