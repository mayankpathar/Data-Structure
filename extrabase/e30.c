// WAP to find a sum of even number into 1D array.
#include <stdio.h>

int main()
{
    int n;
    printf("enter the number of arr element:");
    scanf("%d", &n);
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("enter the arr element :");
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
        {
            sum = sum + arr[i];
        }
    }
    printf("%d", sum);
    return 0;
}