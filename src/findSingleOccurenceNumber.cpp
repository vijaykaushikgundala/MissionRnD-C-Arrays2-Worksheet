/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

int findSingleOccurenceNumber(int *A, int len)
{
	int sum1 = 0,sum2=0, i, result,array[50];
	if (len < 0 || A == nullptr)
	{
		return -1;
	}
	for (i = 0; i < 50; i++)
	{
		array[i] = 0;
	}
	for (i = 0; i < len; i++)
	{
		array[A[i]] = 1;
	}
	for (i = 0; i < 50; i++)
	{
		if (array[i] == 1)
		{
			sum2 = sum2 + i;
		}
	}
	for (i = 0; i < len; i++)
	{
		sum1 = sum1 + A[i];
	}
	result = ((sum2 * 3) - sum1) / 2;
	return result;
}
