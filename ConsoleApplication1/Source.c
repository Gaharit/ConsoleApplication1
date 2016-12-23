#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int main()
{
	char a[SIZE];
	char c;
	int i, j, length;
	printf("Enter a string: ");
	for (i = 0; i < SIZE;) {
		scanf("%c", &c);
		if (c == '\n') {
			length = i;
			j = i - 1;
			break;
		}
			a[i] = c;
			i++;
	}
	for (i = 0; i <= length / 2;) {
		while (a[i] == ' ')
			i++;
		while (a[j] == ' ')
			j--;
		if (a[i] != a[j]) {
			printf("Your string is not a palindrome :(\n");
			return 0;
		}
		i++;
		j--;
	}
	printf("Your string is a palindrome!\n");
}