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
	// extra_y�� ���������� y���� �ߺ��� �������ְ� sort���ֱ�����
	// input_y�� ����� �ʾƾ� ���ʺ��� �ǹ��� ���̼����� �˱⋚����
	for (int i = 1; i <= testcase; i++)
		checker[extra_y[i]] = 1;
	for (int i = 0; i <= 500000; i++)
		if (checker[i] == 1)
			extra_y[noduplication++] = i; //��Ȱ�� 
	noduplication--;
	//extra_y ������

	// �ߺ������� y���� ������ŭ�� for�� ����
	for (int i = noduplication; i > 0; i--) { // ���� ���� �ǹ��� ��ġ���� �ϳ��� ������
		if (extra_y[i] == 0) // ���� 0�̸� ����
			break;

		int xcount = 0;
		for (int f = 1; f <= testcase; f++)
			if (input_y[f] == extra_y[i])
				input_x[xcount++] = f; // ���̰� extra[i]�� �ǹ��� ����� ����

		if (xcount != 1) {
			for (int i = 0; i <= xcount - 1; i++) {
				if (i == xcount - 1) { // ���� input_y[input_x[i]]�� ���� ������ �ǹ��� �����ϸ� ������ count ����
					counter++;
					break;
				}
				for (int f = input_x[i] + 1; f < input_x[i + 1]; f++)
					// ���̰� ���� x ���̻����� ���̰� ������ ���̺��� ������ Ȯ��
					if (input_y[f] < input_y[input_x[i]]) {// ������ �ǹ��� �ѹ��̶� �� ������ ���Ҵٸ�
						counter++;
						break;
					}
				// �׸��� ���̻����� �ǹ����� �翷���� ���Ҵٸ� �׳� ������ (�Ѱ� �ǹ��� ġ��, ���� �ǹ��� ���ٸ� counter++���ٲ��ϱ�)
			}
		} // end of xcount != 1
		else // ���� ������ �ǹ��� ���������ʴ´ٸ� �� count ++
			counter++;
	}
	cout << counter;
}
