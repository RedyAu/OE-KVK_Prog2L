#include <stdio.h>
#include <stdlib.h>

void printnum(int *ptr, int len);
int sumnum(int *ptr, int len);
int sumnotdiv(int check, int *ptr, int len);
int cntbit(int bit, int *ptr, int len);
int prodplace(int *ptr, int len);

int main()
{
	int tomb[] =  {5, 10, 15, 20, 25, 50, 100};
	int* ptr, len = (sizeof(tomb) / sizeof(tomb[0]));
	//int len = sizeof(tomb) / sizeof(tomb[0]);

	for (ptr = tomb; ptr < (tomb + len); ptr++) {
		printf("%10i", *ptr);
	}

	printf("\n");

	printnum(tomb, len);

	printf("\nsum = \t%i\n", sumnum(tomb, len));
	printf("sumnotdiv= \t%i\n", sumnotdiv(3, tomb, len));
	printf("cnt = \t%i\n", cntbit(3, tomb, len));
	printf("prod = \t%i\n", prodplace(tomb, len));

    return 0;
}

int prodplace(int *ptr, int len) {
	int *tomb = ptr, prod = 1;

	for (; ptr < tomb + len; ptr++) {
		if (!((*ptr / 10) % 10)) prod *= *ptr;
	}
	return prod;
}

int cntbit(int bit, int *ptr, int len) {
	int *tomb = ptr, cnt = 0, mask = 1;
	mask <<= bit;
	for (; ptr < tomb + len; ptr++) {
		if (!(mask & *ptr)) cnt++;
	}
	return cnt;
}

int sumnotdiv(int check, int *ptr, int len) {
	int *tomb = ptr, sum = 0;
	for (; ptr < tomb + len; ptr++) {
		if (!(*ptr % 3)) {
			sum += *ptr;
		}
		//sum += *ptr * !!(*ptr % check);
	}
	return sum;
}

int sumnum(int *ptr, int len) {
	int *tomb = ptr, sum = 0;
	for (; ptr < tomb + len; ptr++) {
		sum += *ptr;
	}
	return sum;
}

void printnum(int *ptr, int len) {
	int *tomb = ptr;
	for (; ptr < tomb + len; ptr++) {
		printf("%10i", *ptr);
	}
}
