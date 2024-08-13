// Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm.
#include <stdio.h>
int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main() {
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;  // Use a high value to represent no connection
        }
    }

    visited[1] = 1;  // Start from the first node
    printf("\n");

    while (ne < n) {  // Loop until we include n-1 edges in the MST
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {  // Find the minimum cost edge
                    if (visited[i] != 0) {  // Ensure one end is in the tree
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {  // Check if we can add this edge
            printf("\n Edge %d:(%d %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999;  // Mark the edge as used
    }

    printf("\n Minimum cost = %d\n", mincost);
}
