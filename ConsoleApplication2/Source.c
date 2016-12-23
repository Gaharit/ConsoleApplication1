#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Source2.h"
#define SIZE 50
void main()
{
	FractionalNumber fract_1, fract_2, fract_write;
	char Operation;
	char StInput[SIZE];

	printf("(a)     - reduction\n");
	printf("[a]     - extracting integer part\n");
	printf("a + b   - addition\n");
	printf("a * b   - multiplication\n");
	printf("a / b   - division\n");
	printf("What do you want to do?\n\n");

	gets(StInput);

	if (StInput[0] == '(' || StInput[0] == '[')
	{
		DoFract1(StInput, strlen(StInput), &fract_1);
	}
	else
	{
		DoFract2(StInput, strlen(StInput), &fract_1, &fract_2);
	}
}