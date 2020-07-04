#include <iostream>
#include <math.h>
using namespace std;
int og_input;
bool og_mid = 0;
void structure(int input);

void top_st(int input) {
	if (input == 1) {
		if (og_mid != 1) {

		}
		else {

		}
	}
	else {
		structure(input);
	}
}

void mid_st(int input) {
	if (input == 1) {
		if (og_mid != 1) {

		}
		else {

		}
	}
	else {
		structure(input);
	}
}

void bot_st(int input) {
	if (input == 1) {
		if (og_mid != 1) {

		}
		else {

		}
	}
	else
		structure(input);
}
void structure(int input) {
	for (int i = 0; i < 3; i++)
		top_st(input / 3);
	cout << "\n";
	if (input != og_input)
		for (int i = 0; i < 3; i++)
			mid_st(input / 3);
	else {
		og_mid = 1;
		for (int i = 0; i < 3; i++)	
			mid_st(input / 3);
	}
	cout << "\n";
	if (input == og_input)
		og_mid = 0;
	for (int i = 0; i < 3; i++)
		bot_st(input / 3);
}

int main(void) {
	cin >> og_input;

	structure(og_input);
}