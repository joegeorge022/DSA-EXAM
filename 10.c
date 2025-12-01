#include <stdio.h>

#define MAX 20

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int v) {
    if(front == -1)front = 0;
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int adj[MAX][MAX];
    int vertices, start, i, j;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    printf("Enter starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);
    
    for(i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;
    
    printf("BFS Traversal: ");
    
    while(front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        
        for(i = 0; i < vertices; i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}