#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hashValue(int value) {
    return (value % 18) + 2;
}

void insertValue(int table[], int value) {
    int index;

    index = hashValue(value);

    while (table[index] != -1)
        index = (index + 1) % 20;

    table[index] = value;
}

int main() {
    int table[20];
    int value;
    int i;

    srand(time(NULL));

    for (i = 0; i < 20; i++)
        table[i] = -1;

    for (i = 0; i < 15; i++) {
        value = 100000 + rand() % 900000;
        insertValue(table, value);
    }

    for (i = 0; i < 20; i++)
        printf("Index %d : %d\n", i, table[i]);

    return 0;
}