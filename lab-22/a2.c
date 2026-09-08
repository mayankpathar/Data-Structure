#include <stdio.h>

int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex)
        return vertex;

    parent[vertex] = findParent(parent, parent[vertex]);
    return parent[vertex];
}

void joinSets(int parent[], int first, int second) {
    int firstRoot;
    int secondRoot;

    firstRoot = findParent(parent, first);
    secondRoot = findParent(parent, second);

    if (firstRoot != secondRoot)
        parent[secondRoot] = firstRoot;
}

int countComponents(int weight[], int count) {
    int parent[101];
    int components;
    int i;
    int j;

    components = count;

    for (i = 1; i <= count; i++)
        parent[i] = i;

    for (i = 1; i <= count; i++) {
        for (j = i + 1; j <= count; j++) {
            if (j - i != weight[j] - weight[i]) {
                if (findParent(parent, i) != findParent(parent, j)) {
                    joinSets(parent, i, j);
                    components--;
                }
            }
        }
    }

    return components;
}

int main() {
    int testCases;
    int count;
    int weight[101];
    int i;

    scanf("%d", &testCases);

    while (testCases--) {
        scanf("%d", &count);

        for (i = 1; i <= count; i++)
            scanf("%d", &weight[i]);

        printf("%d\n", countComponents(weight, count));
    }

    return 0;
}
