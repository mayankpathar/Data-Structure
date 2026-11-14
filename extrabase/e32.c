// WAP to delete an element from array specified by user. if element is not found print a message
// “Element is not found” (do not take a new array).
#include <stdio.h>

int main()
{
    int n, m;

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

    for (int i = m - 1; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = NULL;

    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}