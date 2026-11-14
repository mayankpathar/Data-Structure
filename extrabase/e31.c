// WAP to enter an element at specific position into array. (Do not take a new array)
#include <stdio.h>

int main()
{
    int n, m, v;

    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    int arr[n + 1];

    for (int i = 0; i < n; i++)
    {
        printf("Enter array element: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter position: ");
    scanf("%d", &m);

    printf("Enter value: ");
    scanf("%d", &v);

    for (int i = n; i >= m; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[m - 1] = v;

    printf("Array after insertion: ");

    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}