#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Interval {
    int start;
    int end;
};

struct Interval stack[MAX];
int top = -1;

void push(struct Interval x) {
    stack[++top] = x;
}

struct Interval pop() {
    return stack[top--];
}

int compare(const void *a, const void *b) {
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}

int main() {
    int n, i;
    struct Interval arr[MAX];

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    printf("Enter intervals (start end):\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);


    



    push(arr[0]);

    for(i = 1; i < n; i++) {
        struct Interval topInterval = pop();

        if(arr[i].start <= topInterval.end) {
            if(arr[i].end > topInterval.end)
                topInterval.end = arr[i].end;

            push(topInterval);
        } else {
            push(topInterval);
            push(arr[i]);
        }
    }

    printf("\nMerged Intervals:\n");
    for(i = 0; i <= top; i++) {
        printf("[%d, %d]\n", stack[i].start, stack[i].end);
    }

    return 0;
}