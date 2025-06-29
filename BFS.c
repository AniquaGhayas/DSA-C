#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];      // Adjacency matrix
int visited[MAX];       // Visited array for BFS
int queue[MAX];         // Queue implementation
int front = -1, rear = -1;

void enque(int vertex)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        if (front == -1) front = 0;
        queue[++rear] = vertex;
    }
}

int deque()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    return queue[front++];
}

void bfs(int startVertex, int n)
{
    printf("BFS Traversal starting from vertex %d:\n", startVertex);

    visited[startVertex] = 1;
    enque(startVertex);

    while (front <= rear)
        {
        int currentVertex = deque();
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++)
            {
            if (adj[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enque(i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int n, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n > MAX || n <= 0)
    {
        printf("Invalid number of vertices. Please enter between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the starting vertex for BFS (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= n)
    {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    bfs(startVertex, n);

    return 0;
}
