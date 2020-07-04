#include <stdio.h>
int input, card_num, cards[20000002] = { 0 }, mycard_num;

int main(void) {

	scanf("%d", &card_num);
	for (int i = 0; i < card_num; i++) {
		scanf("%d", &input);
		cards[input+10000000] = 1;
	}

	scanf("%d", &mycard_num);
	for (int i = 0; i < mycard_num; i++) {
		scanf("%d", &input);
		printf("%d ", cards[input+10000000]);
	}

}