#include <stdbool.h>
#include <stdlib.h>

bool dfs(int u, int** graph, int* graphColSize, int* estado) {
    estado[u] = 1;

    for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];

        if (estado[v] == 1) {
            return false;
        }

        if (estado[v] == 0 && !dfs(v, graph, graphColSize, estado)) {
            return false;
        }
    }

    estado[u] = 2; // sem ciclo
    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int b = prerequisites[i][1];
        graphColSize[b]++;
    }

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(graphColSize[i] * sizeof(int));
        graphColSize[i] = 0;
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][graphColSize[b]++] = a;
    }

    // 0 = não visitado, 1 = visitando, 2 = concluído
    int* estado = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (estado[i] == 0 && !dfs(i, graph, graphColSize, estado)) {
            return false;
        }
    }

    return true;
}
