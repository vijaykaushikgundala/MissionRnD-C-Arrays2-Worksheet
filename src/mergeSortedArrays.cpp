/*
OVERVIEW: You are given 2 bank statements that are ordered by date -
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int msvalid(int, int, int);
int msOlder(char *dob1, char *dob2)
{
	int i, da1, da2, m1, m2, y1, y2, x, y;
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
	{
		return -1;
	}
	else
	{
		for (i = 0; dob1[i] != '\0'; i++)
		{
			if (i == 2 || i == 5)
			{
				i++;
			}
			x = dob1[i] - '0';
			y = dob2[i] - '0';
			if (x<0 || x>9 || y<0 || y>9)
			{
				return -1;
			}
		}
		da1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
		da2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
		m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
		m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
		y1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
		y2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');
		x = msvalid(da1, m1, y1);
		y = msvalid(da2, m2, y2);
		if (x != 0 || y != 0)
		{
			return -1;
		}
		if (y1 > y2)
		{
			return 2;
		}
		else
		if (y1<y2)
		{
			return 1;
		}
		if (m1>m2)
		{
			return 2;
		}
		else if (m1<m2)
		{
			return 1;
		}
		if (da1>da2)
		{
			return 2;
		}
		else if (da1 < da2)
		{
			return 1;
		}
		return 0;
	}
}

int msvalid(int d, int m, int y)
{
	int leap;
	if (d<0 || m<0 || y <= 0)
	{
		return -1;
	}
	if (m>12)
	{
		return -1;
	}
	if (d>31)
	{
		return -1;
	}
	if (y % 400 == 0)
	{
		leap = 1;
	}
	else if (y % 100 == 0)
	{
		leap = 0;
	}
	else if (y % 4 == 0)
	{
		leap = 1;
	}
	else
		leap = 0;
	if (leap == 0)
	{
		if (m == 9 || m == 4 || m == 6 || m == 11)
		{
			if (d>30)
			{
				return -1;
			}
		}
		if (m == 2 && d>28)
		{
			return -1;
		}
	}
	else
	{
		if (m == 9 || m == 4 || m == 6 || m == 11)
		{
			if (d>30)
			{
				return -1;
			}
		}
		if (m == 2 && d>29)
		{
			return -1;
		}
	}
	return 0;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int i = 0, j = 0, k = 0, result;
	struct transaction *output;
	output = (struct transaction *)malloc(sizeof(struct transaction ) * 10);
	if (A == NULL || B == NULL)
	{
		return NULL;
	}
	while (i < ALen && j < BLen)
	{
		result = msOlder(A[i].date, B[j].date);
		if (result == 1)
		{
			output[k] = A[i];
			k++;
			i++;
		}
		if (result == 2)
		{
			output[k] = B[j];
			k++;
			j++;
		}
		if (result == 0)
		{
			output[k] = A[i];
			k++;
			i++;
		}
	}
	if ((i == ALen) && j < BLen)
	{
		while (j < BLen)
		{
			output[k] = B[j];
			j++;
			k++;
		}
	}
	if ((j == BLen) && i < ALen)
	{
		while (i < ALen)
		{
			output[k] = A[i];
			i++;
			k++;
		}
	}
	return output;

	}