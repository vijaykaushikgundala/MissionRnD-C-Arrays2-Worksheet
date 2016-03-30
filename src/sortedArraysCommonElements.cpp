/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int savalid(int, int, int);
int iOlder(char *dob1, char *dob2)
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
		x = savalid(da1, m1, y1);
		y = savalid(da2, m2, y2);
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

int savalid(int d, int m, int y)
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

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	struct transaction *output;
	output = (struct transaction *)malloc(sizeof(struct transaction *) * 10);
	int i,j,result,flag=0,k=0;
	if (A == NULL || B == NULL)
	{
		return NULL;
	}
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			result = iOlder(A[i].date, B[j].date);
			if (result == -1)
			{
				return NULL;
			}
			if (result == 0)
			{
				flag = 1;
				output[k].amount = A[i].amount;
				k++;
			}
		}
	}
	if (flag == 0)
	{
		return NULL;
	}
	else
	{
		return output;
	}
}