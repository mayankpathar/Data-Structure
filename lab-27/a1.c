#include <stdio.h>

int partition(int values[], int low, int high) {
    int pivot;
    int smaller;
    int current;
    int temporary;

    pivot = values[high];
    smaller = low - 1;

    for (current = low; current < high; current++) {
        if (values[current] < pivot) {
            smaller++;

            temporary = values[smaller];
            values[smaller] = values[current];
            values[current] = temporary;
        }
    }

    temporary = values[smaller + 1];
    values[smaller + 1] = values[high];
    values[high] = temporary;

    return smaller + 1;
}

void quickSort(int values[], int low, int high) {
    int pivotPosition;

    if (low >= high)
        return;

    pivotPosition = partition(values, low, high);

    quickSort(values, low, pivotPosition - 1);
    quickSort(values, pivotPosition + 1, high);
}

int main() {
    int values[100];
    int count;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &values[i]);

    quickSort(values, 0, count - 1);

    for (i = 0; i < count; i++)
        printf("%d ", values[i]);

    return 0;
}
