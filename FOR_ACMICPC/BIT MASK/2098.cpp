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
	//기저 사례: 모든 도시를 다 방문했을 때는 0번 도시로 돌아가고 종료
	if (visited == (1 << N) - 1) {
		if (W[here][0] != 0)
			return W[here][0];
		//다 방문했지만 정작 0으로 다시 돌아가는 길이 없을 경우
		return INF;
	}
 	int& result = cache[here][visited];
	// result == cache[here][visited] 그냥 길이만 줄인 같은 주소, 같은 값의 변수라고 보면 됨.
	if (result != -1)
		// result에는 h -> v까지의 최단경로가 이미 저장되어있다.
		return result;
	result = INF;
	//다음 방문할 도시를 전부 시도
	for (int next = 0; next < N; next++) {
		//이미 방문한 도시         or    갈수없거나
		if (visited & (1 << next) || W[here][next] == 0)
			continue;
		int candidate = W[here][next] + TSP(next, visited + (1 << next));
													//   next에서 0으로 돌아오는 최단경로
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