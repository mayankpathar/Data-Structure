// (1) WAP to sort an Array using Bubble sort.
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the array element: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int m = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = m;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}