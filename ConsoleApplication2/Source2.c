#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fraction
{
	int numerator;
	int denumerator;
};

typedef struct fraction FractionalNumber;

int NOD(int A, int B)
{
	while (A != B)
	{
		if (A > B)
		{
			A -= B;
		}
		else
		{
			B -= A;
		}
	}
	return A;
}

void show_fract(FractionalNumber *pFract)
{
	printf("%d / %d\n", pFract->numerator, pFract->denumerator);
}

void AmountFract(FractionalNumber *pfract_1, FractionalNumber *pfract_2)
{
	int nod;
	FractionalNumber Result;

	Result.denumerator = pfract_1->denumerator * pfract_2->denumerator / NOD(pfract_1->denumerator, pfract_2->denumerator);

	Result.numerator = pfract_1->numerator * (Result.denumerator / pfract_1->denumerator) + pfract_2->numerator * (Result.denumerator / pfract_2->denumerator);

	nod = NOD(Result.denumerator, Result.numerator);

	Result.denumerator = Result.denumerator / nod;

	Result.numerator = Result.numerator / nod;

	show_fract(&Result);
}

void MultiplicationFract(FractionalNumber *pfract_1, FractionalNumber *pfract_2)
{
	int nod;
	FractionalNumber Result;

	Result.denumerator = pfract_1->denumerator * pfract_2->denumerator;
	Result.denumerator = pfract_1->numerator * pfract_2->numerator;

	nod = NOD(Result.denumerator, Result.denumerator);

	Result.denumerator = Result.denumerator / nod;

	Result.denumerator = Result.denumerator / nod;

	show_fract(&Result);
}

void DivisionFract(FractionalNumber *pfract_1, FractionalNumber *pfract_2)
{
	int nod;
	FractionalNumber Result;

	Result.denumerator = pfract_1->denumerator * pfract_2->numerator;
	Result.numerator = pfract_1->numerator * pfract_2->denumerator;

	nod = NOD(Result.denumerator, Result.numerator);

	Result.denumerator = Result.denumerator / nod;

	Result.numerator = Result.numerator / nod;

	show_fract(&Result);
}

void ReductionFract(FractionalNumber *pfract_1)
{
	int nod;

	nod = NOD(pfract_1->denumerator, pfract_1->numerator);

	pfract_1->denumerator = pfract_1->denumerator / nod;
	pfract_1->numerator = pfract_1->numerator / nod;

	show_fract(pfract_1);
}

void IntPartFract(FractionalNumber *pfract_1)
{
	printf("%d", pfract_1->numerator / pfract_1->denumerator);
}

void DoFract1(char *St, int N, FractionalNumber *pfract_1)
{
	int i, flagInput = 1;
	char BuferInput[20] = { "" }, Operation;

	Operation = *(St);

	for (i = 1; i < N - 1; ++i)
	{
		if (*(St + i) == ' ')
		{
			if (flagInput == 1)
			{
				pfract_1->numerator = atoi(BuferInput);
				printf("%d\n", pfract_1->numerator);
			}

			++flagInput;

			BuferInput[0] = '\0';
		}
		else
		{


			BuferInput[strlen(BuferInput) + 1] = '\0';
			BuferInput[strlen(BuferInput)] = *(St + i);
		}
	}

	printf("%s\n", BuferInput);
	pfract_1->denumerator = atoi(BuferInput);


	if (Operation == '(')
	{
		ReductionFract(pfract_1);
	}
	else
	{
		IntPartFract(pfract_1);
	}
}

void DoFract2(char *St, int N, FractionalNumber *pfract_1, FractionalNumber *pfract_2)
{
	int i, flagInput = 1;
	char Operation, BuferInput[20] = { "" };

	for (i = 0; i < N; ++i)
	{
		if (*(St + i) == ' ')
		{
			switch (flagInput)
			{
			case 1:
			{
				pfract_1->numerator = atoi(BuferInput);
				break;
			}
			case 3:
			{
				pfract_1->denumerator = atoi(BuferInput);
				break;
			}
			case 4:
			{
				Operation = BuferInput[0];
				break;
			}
			case 5:
			{
				pfract_2->numerator = atoi(BuferInput);
				break;
			}
			}

			++flagInput;

			BuferInput[0] = '\0';
		}
		else
		{
			BuferInput[strlen(BuferInput)] = *(St + i);
			BuferInput[strlen(BuferInput)] = '\0';
		}
	}

	pfract_2->denumerator = atoi(BuferInput);

	switch ((int)Operation)
	{
	case (int)'+':
	{
		AmountFract(pfract_1, pfract_2);
		break;
	}
	case (int)'*':
	{
		MultiplicationFract(pfract_1, pfract_2);
		break;
	}
	case (int)'/':
	{
		DivisionFract(pfract_1, pfract_2);
		break;
	}
	}
}