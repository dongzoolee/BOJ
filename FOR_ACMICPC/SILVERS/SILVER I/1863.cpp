#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long checker[500002] = { 0 };

int main(void) {
	long testcase, input_x[50002] = { 0 }, check_x[50002] = { 0 }, extra_y[50002], input_y[50002], counter = 0, trash, noduplication = 1;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++) {
		cin >> trash >> input_y[i];
		extra_y[i] = input_y[i];
	}
	sort(extra_y, extra_y + testcase);
	// extra_y를 만든이유는 y값의 중복을 제거해주고 sort해주기위해
	// input_y에 덮어쓰지 않아야 왼쪽부터 건물의 높이순서를 알기떄문에
	for (int i = 1; i <= testcase; i++)
		checker[extra_y[i]] = 1;
	for (int i = 0; i <= 500000; i++)
		if (checker[i] == 1)
			extra_y[noduplication++] = i; //재활용 
	noduplication--;
	//extra_y 생성끝

	// 중복제거한 y값의 개수만큼만 for문 돌림
	for (int i = noduplication; i > 0; i--) { // 제일 높은 건물의 위치부터 하나씩 내려옴
		if (extra_y[i] == 0) // 높이 0이면 종료
			break;

		int xcount = 0;
		for (int f = 1; f <= testcase; f++)
			if (input_y[f] == extra_y[i])
				input_x[xcount++] = f; // 높이가 extra[i]인 건물이 몇개인지 센다

		if (xcount != 1) {
			for (int i = 0; i <= xcount - 1; i++) {
				if (i == xcount - 1) { // 높이 input_y[input_x[i]]에 대해 마지막 건물에 도달하면 무조건 count 해줌
					counter++;
					break;
				}
				for (int f = input_x[i] + 1; f < input_x[i + 1]; f++)
					// 높이가 같은 x 사이사이의 높이가 양쪽의 높이보다 높은지 확인
					if (input_y[f] < input_y[input_x[i]]) {// 사이의 건물이 한번이라도 양 옆보다 낮았다면
						counter++;
						break;
					}
				// 그리고 사이사이의 건물들이 양옆보다 높았다면 그냥 개무시 (한개 건물로 치고, 사이 건물이 낮다면 counter++해줄꺼니까)
			}
		} // end of xcount != 1
		else // 같은 높이인 건물이 존재하지않는다면 걍 count ++
			counter++;
	}
	cout << counter;
}
