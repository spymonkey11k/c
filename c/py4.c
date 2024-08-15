// EXP - 4
// Design and implement C/C++ Program to find shortest paths from a given vertex in a weighted
// connected graph to other vertices using Dijkstra's algorithm.//
#include <stdio.h>

#define infinity 999

void dij(int n, int v, int cost[10][10], int dist[10]) {
    int i, u = 0, count, w, flag[10], min;

    for (i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }

    count = 2;
    while (count <= n) {
        min = infinity;
        for (w = 1; w <= n; w++) {
            if (dist[w] < min && !flag[w]) {
                min = dist[w];
                u = w;
            }
        }

        flag[u] = 1;
        count++;

        for (w = 1; w <= n; w++) {
            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

void main() {
    int n, v, i, j, cost[10][10], dist[10];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = infinity;
            }
        }
    }

    printf("\nEnter the source node: ");
    scanf("%d", &v);

    dij(n, v, cost, dist);

    printf("\nShortest path:\n");
    for (i = 1; i <= n; i++) {
        if (i != v) {
            printf("%d -> %d, cost = %d\n", v, i, dist[i]);
        }
    }
}

Enter the cost matrix:
0 3 999  7 999 
3 0 4 2 999 
999 4 0 5 6 
999 4 0 5 6 
7 2 5 0 4

Enter the source node: 11

Shortest path:
11 -> 1, cost = 1
11 -> 2, cost = 4
11 -> 3, cost = 0
11 -> 4, cost = 5
11 -> 5, cost = 6
