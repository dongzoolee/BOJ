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
	//abc bca 예시에서 사고의 오류 . a가 b로 바꼈다고 꼭 b도 a로 바껴야하는건아님.
	for (int f = 0; f < tc; f++)
		for (int h = f + 1; h < tc; h++) {
			bool falsechecker = 0;	// alpha[h의문자]의 값과 f의 값이 일치하지 않으면 falsechecker=1
			char alpha[26] = { 0 };	// h에 대응되는 f의 문자를 alpha[h의문자]에 저장
			bool alpha_check[26] = { 0 }; // alpha[h의문자]에 저장된 f의 문자는 bool을 1로 만듦.
			for (int i = 0; i < 26; i++) {
				for (int z = 0; z < strlen(ch[h]); z++) {
					if (ch[h][z] == (char)(i + 97) && alpha[ch[h][z] - 97] == 0 && alpha_check[ch[f][z] - 97] == 0) { 
						alpha[ch[h][z] - 97] = ch[f][z];	// h에 대응되는 f의 문자를 alpha[h의문자]에 저장
						alpha_check[ch[f][z] - 97] = 1;		// alpha[h의문자]에 저장된 f의 문자는 bool을 1로 만듦. 이미저장된 f의문자 중복저장방지.
					}
					else if (ch[h][z] == (char)(i + 97))
						if (alpha[ch[h][z] - 97] != ch[f][z]) {	// h에 대응되는 f의문자가 alpha[h의문자]와 다르면 false=1
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