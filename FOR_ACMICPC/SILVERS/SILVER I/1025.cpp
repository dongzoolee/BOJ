#include <iostream>
using namespace std;
int arr[10][10], order[102], ct = 0, powray[10000][100], f = 0, g = 1;

void putpowinarray(int end) {
	for (int i = 1; i <= end; i++)
		while (1) {
			if ((int)log10(pow(g, 2)) + 1 == i)
				powray[f++][i] = (int)pow(g++, 2);
			else
				break;
		}
}

void arrayinput(int n, int m) {
	string sentence;
	for (int h = 1; h <= n; h++) {
		cin >> sentence;
		for (int f = 1; f <= m; f++) {
			arr[h][f] = sentence.at(f - 1) - 48;
			order[ct] = sentence.at(f - 1) - 48;
			ct++;
		}
	}
}

int main() {
	int N, M, makingnum = 0, g, temp, max, f = 0, savingnumbers[101], savingnumb_counter = 0;
	cin >> N >> M;
	arrayinput(N, M);
	putpowinarray(N * M);

	for (int i = 1; i <= N * M; i++) { //¾Æ¿ôÇ² ÀÚ¸® ¼ö
			while ((int)log10(powray[f][i]) + 1 == i) {
				int g;
				for (int z = 0; z < i; z++) {
					bool innerbool = 0;
					for (g = 0; g < M * N; g++)
						if (powray[f][i] / (int)pow(10, z) == order[g])
							innerbool = 1;
					powray[f][i] %= (int)pow(10, z);
					if (innerbool != 1) {
						f++;
						break;
					}
					else
						savingnumbers[savingnumb_counter++] = order[g];
				}
			}//end of while

	}
}