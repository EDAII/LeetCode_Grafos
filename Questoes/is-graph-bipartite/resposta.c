#include <stdbool.h>
#include <stdlib.h>

bool dfs(int u, int** graph, int* graphColSize, int* cor) {
    for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];

        if (cor[v] == 0) {
            cor[v] = -cor[u];
            if (!dfs(v, graph, graphColSize, cor)) {
                return false;
            }
        } else if (cor[v] == cor[u]) {
            return false;
        }
    }

    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* cor = (int*)calloc(graphSize, sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        if (cor[i] == 0) {
            cor[i] = 1;
            if (!dfs(i, graph, graphColSize, cor)) {
                return false;
            }
        }
    }

    return true;
}
