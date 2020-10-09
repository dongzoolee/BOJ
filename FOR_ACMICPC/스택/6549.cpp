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
		// ���ÿ� ����idx & ���� ��������
		stack <pair<int, ll>>st;
		for (int f = 0; f < a; f++)
			cin >> inp[f];

		// ���� ū ���簢�� ���� ���� ��
		ll max_ = 0;
		for (int i = 0; i < a; i++) {

			// ���� ó������ �ϴ� �־���
			if (!st.size()) {
				st.push({ i, inp[i] });
			}
			else if (st.top().second <= inp[i]) {
				// ���� ���� �ִ� �ǹ����� stack top�� �ִ� ���� ������ ��� push
				st.push({ i, inp[i] });
			}
			else {
				// stack top �ǹ� ũ�⺸�� ���� �ǹ��� ������
				while (st.size() && st.top().second > inp[i]) {
					// ������ ���� �ǹ� ���� �� ���� ��� pop ���ٰǵ�
					max_ = max(max_, (i - st.top().first) * st.top().second);
					// pop�� �ǹ����� ���� ���� ����� ġ�� ���� ��������
					// = �ǹ� �ε����� i�� �ƴ϶� (i - ���� ���� �ǹ� ��)�� �Ұ��� (== last)
					last = st.top().first;
					// �׷��� �׳� top�� idx�� �����ؼ� ������ �������
					// = �׷��� �ǹ� ũ�� ���� �͵� ������ �ȵ�
					// �ֳĸ� ������ i�� �� �ǹ� ���� idx�������� Ŀ�� ����
					// ���� (i-���� �ǹ� ��)�� ���ο� idx�� ���� ������
					// �������� �ǹ� idx - ���� ���ο� idx
					// = �������� �ǹ� idx - (�� ���� i - ����ǹ���)
					// �������� �ǹ� idx - �� ���� i �� �� �տ� �ִ�, ������ ũ�ų� ���� �ǹ� ��
					// +����ǹ����� �� ���� ������ ũ�ų� ���� �ǹ� �� �� ���Ǿ�
					// ���������� ���� ����.
					st.pop();
				}
				st.push({ last, inp[i] });
			}
		}
		 
		// stack�� ���� �͵� �� ó�� //
		// n��° �ǹ�(�����δ� ���� �ǹ�)�� ���� 0�� �ǹ��̶�� �����Ͽ�
		// stack�� �ִ� �ǹ����� �� 0���� ���� �ǹ����� �Ź���
		// = �� ����
		while (st.size()) {
			max_ = max(max_, (a - st.top().first) * st.top().second);
			st.pop();
		}
		cout << max_ << '\n';
	}
}