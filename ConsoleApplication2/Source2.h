#pragma once
struct fraction
{
	int numerator;
	int denumerator;
};

typedef struct fraction FractionalNumber;

int NOD(int A, int B);
void AmountFract(FractionalNumber *pfract_1, FractionalNumber *pfract_2);
void MultiplicationFract(FractionalNumber *pfract_1, FractionalNumber *pfract_2);
void DivisionFract(FractionalNumber *pfract_1, FractionalNumber *pfract_2);
void ReductionFract(FractionalNumber *pfract_1);
void IntPartFract(FractionalNumber *pfract_1);
void DoFract1(char *St, int N, FractionalNumber *pfract_1);
void DoFract2(char *St, int N, FractionalNumber *pfract_1, FractionalNumber *pfract_2);
