#include <stdio.h>

void sortColors(int values[], int count) {
    int red;
    int current;
    int blue;
    int temporary;

    red = 0;
    current = 0;
    blue = count - 1;

    while (current <= blue) {
        if (values[current] == 0) {
            temporary = values[red];
            values[red] = values[current];
            values[current] = temporary;

            red++;
            current++;
        } else if (values[current] == 2) {
            temporary = values[current];
            values[current] = values[blue];
            values[blue] = temporary;

            blue--;
        } else {
            current++;
        }
    }
}

int main() {
    int values[100];
    int count;
    int i;

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        scanf("%d", &values[i]);

    sortColors(values, count);

    for (i = 0; i < count; i++)
        printf("%d ", values[i]);

    return 0;
}
