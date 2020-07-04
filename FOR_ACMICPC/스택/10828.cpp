#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
vector <int> v(10000, 0);
int stack_size = 0;

void push(int n) {
	v[stack_size] = n;
	stack_size++;
}

void top() {
	if (stack_size == 0)
		cout << "-1\n";
	else
		cout << v[stack_size - 1] << "\n";
}

void size() {
	cout << stack_size << "\n";
}

void empty() {
	if (stack_size == 0)
		cout << "1" << "\n";
	else
		cout << "0" << "\n";
}

void pop() {
	if (stack_size == 0)
		cout << "-1\n";
	else {
		cout << v[stack_size - 1] << "\n";
		stack_size--;
	}
}

int main() {
	string str;
	int TC, num;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			push(num);
		}
		else if (str == "top")
			top();
		else if (str == "size")
			size();
		else if (str == "empty")
			empty();
		else if (str == "pop")
			pop();
	}
}