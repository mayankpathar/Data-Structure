#include <stdio.h>

void merge(int values[], int left, int middle, int right) {
    int temporary[100];
    int first;
    int second;
    int position;
    int i;

    first = left;
    second = middle + 1;
    position = 0;

    while (first <= middle && second <= right) {
        if (values[first] <= values[second])
            temporary[position++] = values[first++];
        else
            temporary[position++] = values[second++];
    }

    while (first <= middle)
        temporary[position++] = values[first++];

    while (second <= right)
        temporary[position++] = values[second++];

    for (i = 0; i < position; i++)
        values[left + i] = temporary[i];
}

void mergeSort(int values[], int left, int right) {
    int middle;

    if (left >= right)
        return;

    middle = (left + right) / 2;

    mergeSort(values, left, middle);
    mergeSort(values, middle + 1, right);

    merge(values, left, middle, right);
}

int main() {
    int values[100];
    int count;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &values[i]);

    mergeSort(values, 0, count - 1);

    for (i = 0; i < count; i++)
        printf("%d ", values[i]);

    return 0;
}
