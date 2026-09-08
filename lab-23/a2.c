#include <stdio.h>

int hashValue(int value) {
    int index;

    index = value % 50;

    if (index < 0)
        index = index + 50;

    return index;
}

void insertValue(int values[], int used[], int value) {
    int index;

    index = hashValue(value);

    while (used[index] == 1 && values[index] != value)
        index = (index + 1) % 50;

    values[index] = value;
    used[index] = 1;
}

int searchValue(int values[], int used[], int value) {
    int index;
    int start;

    index = hashValue(value);
    start = index;

    while (used[index] == 1) {
        if (values[index] == value)
            return 1;

        index = (index + 1) % 50;

        if (index == start)
            return 0;
    }

    return 0;
}

int main() {
    int values[50];
    int used[50] = {0};
    int count;
    int value;
    int i;

    printf("Enter number of values: ");
    scanf("%d", &count);

    printf("Enter values: ");

    for (i = 0; i < count; i++) {
        scanf("%d", &value);
        insertValue(values, used, value);
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    if (searchValue(values, used, value))
        printf("Present\n");
    else
        printf("Not present\n");

    return 0;
}
