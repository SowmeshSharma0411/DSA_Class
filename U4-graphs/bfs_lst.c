// Breadth First Search (BFS) Traversal using adjacency list
// For a connected/disconnected graph
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node
{
    int info;
    struct node *next;
} NODE;
void createGraph(NODE *V[MAX], int n);
void bfs(NODE *V[MAX], int n, int visited[MAX], int src);
int main()
{
    int n;
    NODE *V[MAX] = {NULL};
    int visited[MAX] = {0};
    int src;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);

    printf("Enter adjacency info\n");
    createGraph(V, n);

    printf("Enter the source vertex\n");
    scanf("%d", &src);

    printf("BFS Traversal\n");
    bfs(V, n, visited, src);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("\n");
            bfs(V, n, visited, i);
        }
    }
}
void addEdge(NODE *V[MAX], int src, int dest)
{
    NODE *newNode = malloc(sizeof(newNode));

    newNode->info = dest;
    newNode->next = V[src];
    V[src] = newNode;
}
void createGraph(NODE *V[MAX], int n)
{
    printf("Enter -1 -1 to stop adding edges\n");
    int src, dest;
    while (1)
    {
        scanf("%d%d", &src, &dest);
        if (src < 0 || dest < 0 || src >= n || dest >= n)
            break;
        addEdge(V, src, dest);
    }
}
void bfs(NODE *V[MAX], int n, int visited[MAX], int src)
{
    int q[n];
    int front = 0, rear = -1;

    q[++rear] = src;
    visited[src] = 1;

    int popped;
    while (front <= rear)
    {
        popped = q[front++];
        printf("%d ", popped);
        NODE *temp = V[popped];
        while (temp)
        {
            if (!visited[temp->info])
            {
                q[++rear] = temp->info;
                visited[temp->info] = 1;
            }
            temp = temp->next;
        }
    }
}