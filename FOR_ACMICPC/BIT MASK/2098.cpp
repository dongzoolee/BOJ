#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;
const int MAX = 16;
const int INF = 987654321;
int N;
int W[MAX][MAX];
int cache[MAX][1 << MAX];

int TSP(int here, int visited) {
	//���� ���: ��� ���ø� �� �湮���� ���� 0�� ���÷� ���ư��� ����
	if (visited == (1 << N) - 1) {
		if (W[here][0] != 0)
			return W[here][0];
		//�� �湮������ ���� 0���� �ٽ� ���ư��� ���� ���� ���
		return INF;
	}
 	int& result = cache[here][visited];
	// result == cache[here][visited] �׳� ���̸� ���� ���� �ּ�, ���� ���� ������� ���� ��.
	if (result != -1)
		// result���� h -> v������ �ִܰ�ΰ� �̹� ����Ǿ��ִ�.
		return result;
	result = INF;
	//���� �湮�� ���ø� ���� �õ�
	for (int next = 0; next < N; next++) {
		//�̹� �湮�� ����         or    �������ų�
		if (visited & (1 << next) || W[here][next] == 0)
			continue;
		int candidate = W[here][next] + TSP(next, visited + (1 << next));
													//   next���� 0���� ���ƿ��� �ִܰ��
		result = min(result, candidate);
	}
	return result;
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];

	int result = INF;
	memset(cache, -1, sizeof(cache));
	cout << TSP(0, 1) << '\n';
	return 0;
}