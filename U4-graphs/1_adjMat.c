// Adjacency Matrix representation of a graph
#include <stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX], int n);
void displayGraph(int adj[MAX][MAX], int n);

int main()
{
    int n;
    // init list :
    int adj[MAX][MAX] = {0};

    printf("Enter the number of vertices\n");
    scanf("%d", &n);

    printf("Enter adjacency information\n");
    createGraph(adj, n);

    printf("Graph in its matrix format\n");
    displayGraph(adj, n);
}
void createGraph(int adj[MAX][MAX], int n)
{
    printf("Enter -1 -1 to stop adding :\n");
    int src, dest;
    while (1)
    {
        scanf("%d %d", &src, &dest);
        if (src < 0 || dest < 0 || src >= n || dest >= n)
            break;
        adj[src][dest] = 1;
    }
}
void displayGraph(int adj[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", adj[i][j]);
        }
        printf("\n");
    }
}