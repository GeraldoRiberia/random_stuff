#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void createGraph(int vertices);
void displayGraph(int vertices);
void DFS(int vertex, int vertices);
void BFS(int start, int vertices);
void enqueue(int vertex);
void clear(int vertices);
int dequeue();

int main() {
    int vertices, choice,vt;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    createGraph(vertices);

    do {
        printf("\nGraph Operations:\n");
        printf("1. Display Graph\n");
        printf("2. DFS Traversal\n");
        printf("3. BFS Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayGraph(vertices);
                break;
            case 2:
                printf("DFS Traversal: ");
                printf("Enter starting vertex");
                scanf("%d", &vt);
                DFS(vt, vertices); // Start DFS from vertex 0
                clear(vertices);
                printf("\n");
                break;
            case 3:
                printf("BFS Traversal: ");
                printf("Enter starting vertex");
                scanf("%d", &vt);
                BFS(vt, vertices); // Start BFS from vertex 0
                clear(vertices);               
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void createGraph(int vertices) {
    int i, j;

    for (i = 0; i < vertices; i++) {
        visited[i] = 0; // Initialize visited array
        for (j = 0; j < vertices; j++) {
            printf("Enter 1 if there is an edge from vertex %d to %d, else enter 0: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
}

void clear(int vertices){
    for(int i = 0; i<vertices; i++){
        visited[i] = 0;
    }
}

void displayGraph(int vertices) {
    int i, j;

    printf("Adjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void DFS(int vertex, int vertices) {
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

void BFS(int start, int vertices) {
    int i, vertex;

    enqueue(start);
    visited[start] = 1;

    while (!(front == -1 && rear == -1)) {
        vertex = dequeue();
        printf("%d ", vertex);

        for (i = 0; i < vertices; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    int vertex;

    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }

    vertex = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return vertex;
}
