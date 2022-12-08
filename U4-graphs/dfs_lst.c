// DFS traversal for a connected graph
// Adjacency List representation

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node
{
    int info;
    struct node *next;
} NODE;
void createGraph(NODE *V[MAX], int n);
void dfs(NODE *V[MAX], int n, int visited[MAX], int src);
int main()
{
    int n, src;

    NODE *V[MAX] = {NULL};
    int visited[MAX] = {0};

    printf("Enter the no. of vertices\n");
    scanf("%d", &n);

    printf("Enter the adjacency information\n");
    createGraph(V, n);

    printf("Enter the source vertex\n");
    scanf("%d", &src);

    printf("DFS traversal\n");
    dfs(V, n, visited, src);
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
void dfs(NODE *V[MAX], int n, int visited[MAX], int src)
{
    visited[src] = 1;
    printf("%d ", src);
    NODE *p = V[src];
    while (p)
    {
        if (visited[p->info] == 0)
            dfs(V, n, visited, p->info);
        p = p->next;
    }
}