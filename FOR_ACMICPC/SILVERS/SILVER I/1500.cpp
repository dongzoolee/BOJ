#include <iostream>
#include <limits.h>
using namespace std;
long S, K, arr[101], end_number, counter = 0;
long long maxi = 1, temp = 1;

int main() {
	cin >> S >> K;
	if (S % K == 0) // 대가리 숫자가 몇일 때까지 분배 진행 ?
		end_number = S / K;
	else
		end_number = S / K + 1;

	//기본적으로 arr[0]을 제외하고 1을 채워넣고 시작
	arr[0] = S - K + 1;
	for (int i = 1; i < K; i++)
		arr[i] = 1;

VI:while (arr[0] >= end_number) { // 커맨드 센터
	int i = 1; counter++;
	if (counter == S - K + 2) // 모냐 ㄱㄷ
		break;

VII:		if (arr[i - 1] - arr[i] < 2) { // 앞뒤 차이가 2가 안될 때 = 다시 arr[0]로 돌아감
	//곱
	temp = 1; // 임시 곱셈공간 초기화
	for (int g = 0; g <= i; g++)
		temp *= arr[g];
	if (temp > maxi)
		maxi = temp;
		goto VI;
}
else {
	if (i != K) { // 앞뒤 차이가 2이상이고, 끝 도달 안했을 경우
		temp = 1; // 임시 곱셈공간 초기화

		arr[i - 1]--;
		arr[i]++;

		for (int g = 0; g <= i; g++)
			temp *= arr[g];
		if (temp > maxi)
			maxi = temp;

		i++;
		goto VII;
	}
	else {
		temp = 1; // 임시 곱셈공간 초기화
		for (int g = 0; g < i; g++)
			temp *= arr[g];
		if (temp > maxi)
			maxi = temp;

			goto VI;
	}
}
}
cout << maxi;


}