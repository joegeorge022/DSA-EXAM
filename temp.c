#include <stdio.h>

#define MAX 20

int queue[MAX],front=-1,rear=-1;
int visited[MAX];

void enqueue(int value){
    if (front==-1) front = 0;
    queue[++rear] = value;
}

int dequeue(){
    return queue[front++];
}

int main(){
    int vertices,i,j,start;
    int adj[MAX][MAX];

    printf("Enter no of vertices: ");
    scanf("%d",&vertices);

    for(int i=0;i<vertices;i++){
        visited[i]=0;
    }

    printf("Enter adjacency matrix: ");
    for(int i=0;i<vertices;i++){
        for (int j = 0; j < vertices; j++){
            scanf("%d",&adj[i][j]);
        }  
    }

    printf("Enter starting vertex(0 to %d): ",vertices-1);
    scanf("%d",&start);

    enqueue(start);
    visited[start]=1;

    printf("BFS TRAVERSAL: ");
    while(front<=rear){
        int v = dequeue();
        printf("%d",v);
        for(int i=0;i<vertices;i++){
            if(visited[i]==0 && adj[v][i]==1){
                enqueue(i);
                visited[i]=1;
            }
        }
    }

    
}