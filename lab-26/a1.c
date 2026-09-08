#include <stdio.h>

void insertionSort(int values[], int count) {
    int i;
    int j;
    int current;

    for (i = 1; i < count; i++) {
        current = values[i];
        j = i - 1;

        while (j >= 0 && values[j] > current) {
            values[j + 1] = values[j];
            j--;
        }

        values[j + 1] = current;
    }
}

int main() {
    int values[100];
    int count;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &values[i]);

    insertionSort(values, count);

    for (i = 0; i < count; i++)
        printf("%d ", values[i]);

    return 0;
}
