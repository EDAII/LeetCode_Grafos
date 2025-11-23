#include <stdbool.h>

void dfs(int u, int** rooms, int* roomsColSize, bool* visitado) {
    visitado[u] = true;
 
    for (int i = 0; i < roomsColSize[u]; i++) {
        int chave = rooms[u][i];
        if (!visitado[chave]) {
            dfs(chave, rooms, roomsColSize, visitado);
        } 
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visitado = (bool*)calloc(roomsSize, sizeof(bool));

    dfs(0, rooms, roomsColSize, visitado);
    for (int i = 0; i < roomsSize; i++) {
        if (!visitado[i]) {
            return false;
        }
    }

    return true;
}
