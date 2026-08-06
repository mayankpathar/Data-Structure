// You are given an array of positive integers and an integer K. Find the length of the longest subarray such that the sum of the subarray is less than or equal to K.
// Input:
// • An array arr[] of size N
// • An integer K
// Output:
// • Length of the longest subarray with sum ≤ K

#include <stdio.h>

int main()
{
	int n, k;
	printf("enter the arr size: ");
	scanf("%d", &n);

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		printf("enter the arr element: ");
		scanf("%d", &arr[i]);
	}

	printf("enter the value of K: ");
	scanf("%d", &k);

	int j = 0;
	int sum = 0;
	int ml = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];

		while (sum > k && j <= i)
		{
			sum -= arr[j];
			j++;
		}

		int cl = i - j + 1;
		if (cl > ml)
		{
			ml = cl;
		}
	}

	printf("%d", ml);

	return 0;
}
