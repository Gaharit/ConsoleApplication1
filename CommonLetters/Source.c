#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>


int QualLineInFile(FILE * pFile)
{
	char InputChar;
	int Qual = 0, flag = 0;

	if (pFile != NULL)
	{
		while (!feof(pFile))
		{
			InputChar = fgetc(pFile);
			if (InputChar != EOF)
			{
				flag = 1;
				if (InputChar == '\n')
					Qual++;
			}
		}

		if (flag == 1)
		{
			Qual++;
		}

		return Qual;
	}
}

void main()
{

	FILE *pFile;
	char Temp[100], open = 'a', close = 'z', OPEN = 'A', CLOSE = 'Z';
	int Qual_read, flag_END = 1, N = 100, i, mass_qual_letter_find['z' - 'a' + 1], MaxLetter = 0, NumerMax, N1 = 'z' - 'a' + 1;

	pFile = fopen("song.txt", "r");

	if (pFile != NULL)
	{
		for (i = 0; i < N1; ++i)
		{
			mass_qual_letter_find[i] = 0;
		}

		while (flag_END)
		{
			Qual_read = fread(Temp, sizeof(char), N, pFile);
			if (Qual_read < N)
				flag_END = 0;

			for (i = 0; i < Qual_read; ++i)
			{
				if (Temp[i] >= OPEN && Temp[i] <= CLOSE)
				{
					mass_qual_letter_find[Temp[i] - OPEN] += 1;
				}

				if (Temp[i] >= open && Temp[i] <= close)
				{
					mass_qual_letter_find[Temp[i] - open] += 1;
				}
			}
		}

		fclose(pFile);

		for (i = 0; i < N1; ++i)
		{
			if (mass_qual_letter_find[i] > MaxLetter)
			{
				MaxLetter = mass_qual_letter_find[i];
				NumerMax = i;
			}
		}
	}

	if (MaxLetter != 0)
	{
		printf("%c\n", (char)((int)open + NumerMax));
	}
	else
	{
		printf("No");
	}
}