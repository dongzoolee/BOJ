#include <iostream>
using namespace std;
int nodes, ended, counter = 0, arr[51], check[51] = { 0 };

void parent(int num) {
	if (check[num + 1] != 0)
		for (int i = 0; i < nodes; i++) {
			if (arr[i] == num)
				parent(i);
		}
	else if (check[arr[num] + 1] != 1)
		counter--;
	else if (check[arr[num] + 1] == 1 && arr[ended] == -1)
		counter--;
}

int main(void) {
	cin >> nodes;

	for (int i = 0; i < nodes; i++)
		cin >> arr[i];

	for (int i = 0; i < nodes; i++)
		for (int f = 0; f <= nodes; f++)
			if (arr[i] == f - 1)
				check[f]++;

	for (int i = 0; i <= nodes; i++)
		if (check[i] == 0)
			counter++;
	cin >> ended;
	parent(ended);
	cout << counter;

}