/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int valid(int, int, int);
int isOlder(char *dob1, char *dob2)
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
		x = valid(da1, m1, y1);
		y = valid(da2, m2, y2);
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

int valid(int d, int m, int y)
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

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int i, result, count = 0, present = 1;
	for (i = 0; i <= len; i++)
	{
		present = isOlder(date, Arr[i].date);
		if (present == 0)
		{
			break;
		}
	}
	if (present == 0)
	{

		for (i = 0; i <=len; i++)
		{
			result = isOlder(Arr[i].date, date);
			if (result == 2)
			{
				count++;
			}
		}
		return count;
	}
	else
	{
		return 0;
	}
}
