#include <iostream>
#include <limits.h>
using namespace std;
long S, K, arr[101], end_number, counter = 0;
long long maxi = 1, temp = 1;

int main() {
	cin >> S >> K;
	if (S % K == 0) // �밡�� ���ڰ� ���� ������ �й� ���� ?
		end_number = S / K;
	else
		end_number = S / K + 1;

	//�⺻������ arr[0]�� �����ϰ� 1�� ä���ְ� ����
	arr[0] = S - K + 1;
	for (int i = 1; i < K; i++)
		arr[i] = 1;

VI:while (arr[0] >= end_number) { // Ŀ�ǵ� ����
	int i = 1; counter++;
	if (counter == S - K + 2) // ��� ����
		break;

VII:		if (arr[i - 1] - arr[i] < 2) { // �յ� ���̰� 2�� �ȵ� �� = �ٽ� arr[0]�� ���ư�
	//��
	temp = 1; // �ӽ� �������� �ʱ�ȭ
	for (int g = 0; g <= i; g++)
		temp *= arr[g];
	if (temp > maxi)
		maxi = temp;
		goto VI;
}
else {
	if (i != K) { // �յ� ���̰� 2�̻��̰�, �� ���� ������ ���
		temp = 1; // �ӽ� �������� �ʱ�ȭ

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
		temp = 1; // �ӽ� �������� �ʱ�ȭ
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