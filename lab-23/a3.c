#include <stdio.h>

int hashValue(int key) {
    int index;

    index = key % 50;

    if (index < 0)
        index = index + 50;

    return index;
}

void insertPair(int keys[], int values[], int used[],
                int key, int value) {
    int index;

    index = hashValue(key);

    while (used[index] == 1 && keys[index] != key)
        index = (index + 1) % 50;

    keys[index] = key;
    values[index] = value;
    used[index] = 1;
}

int searchPair(int keys[], int values[], int used[],
               int key, int *value) {
    int index;
    int start;

    index = hashValue(key);
    start = index;

    while (used[index] == 1) {
        if (keys[index] == key) {
            *value = values[index];
            return 1;
        }

        index = (index + 1) % 50;

        if (index == start)
            return 0;
    }

    return 0;
}

int main() {
    int keys[50];
    int values[50];
    int used[50] = {0};
    int count;
    int key;
    int value;
    int i;

    printf("Enter number of pairs: ");
    scanf("%d", &count);

    printf("Enter key and value:\n");

    for (i = 0; i < count; i++) {
        scanf("%d %d", &key, &value);
        insertPair(keys, values, used, key, value);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    if (searchPair(keys, values, used, key, &value))
        printf("Value = %d\n", value);
    else
        printf("Key not found\n");

    return 0;
}
