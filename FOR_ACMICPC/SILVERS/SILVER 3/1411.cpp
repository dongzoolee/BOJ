#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
char ch[102][52];

int main() {
	int tc, counter = 0;
	string str[100];
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> str[i];
		strcpy(ch[i], str[i].c_str());
	}
	//abc bca ���ÿ��� ����� ���� . a�� b�� �ٲ��ٰ� �� b�� a�� �ٲ����ϴ°Ǿƴ�.
	for (int f = 0; f < tc; f++)
		for (int h = f + 1; h < tc; h++) {
			bool falsechecker = 0;	// alpha[h�ǹ���]�� ���� f�� ���� ��ġ���� ������ falsechecker=1
			char alpha[26] = { 0 };	// h�� �����Ǵ� f�� ���ڸ� alpha[h�ǹ���]�� ����
			bool alpha_check[26] = { 0 }; // alpha[h�ǹ���]�� ����� f�� ���ڴ� bool�� 1�� ����.
			for (int i = 0; i < 26; i++) {
				for (int z = 0; z < strlen(ch[h]); z++) {
					if (ch[h][z] == (char)(i + 97) && alpha[ch[h][z] - 97] == 0 && alpha_check[ch[f][z] - 97] == 0) { 
						alpha[ch[h][z] - 97] = ch[f][z];	// h�� �����Ǵ� f�� ���ڸ� alpha[h�ǹ���]�� ����
						alpha_check[ch[f][z] - 97] = 1;		// alpha[h�ǹ���]�� ����� f�� ���ڴ� bool�� 1�� ����. �̹������ f�ǹ��� �ߺ��������.
					}
					else if (ch[h][z] == (char)(i + 97))
						if (alpha[ch[h][z] - 97] != ch[f][z]) {	// h�� �����Ǵ� f�ǹ��ڰ� alpha[h�ǹ���]�� �ٸ��� false=1
							falsechecker = 1;
							break;
						}
				}
				if (falsechecker == 0 && i == 25) {
					counter++;
				}
				else if (falsechecker == 1)
					break;
			}
		}
	cout << counter << "\n";
}