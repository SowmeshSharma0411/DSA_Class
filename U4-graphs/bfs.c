// Breadth First Search (BFS) Traversal using adjacency matrix
// For a connected/disconnected undirected graph
#include <stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX], int n);
void bfs(int adj[MAX][MAX], int n, int visited[MAX], int src);
int connected(int adj[MAX][MAX], int n, int visited[MAX]);
int checkPath(int adj[MAX][MAX], int n, int visited[MAX], int src, int dest);
int connectedComponent(int adj[MAX][MAX], int n, int visited[MAX]);

int stronglyConnected(int adj[MAX][MAX], int n, int visited[MAX]);
void removeEdgeDirection(int a[MAX][MAX], int b[MAX][MAX], int n);
int weaklyConnected(int adj[MAX][MAX], int n, int visited[MAX]);
int main()
{
    int n;
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int src;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);

    printf("Enter adjacency info\n");
    createGraph(adj, n);

    printf("Enter the source vertex\n");
    scanf("%d", &src);

    printf("BFS Traversal\n");
    bfs(adj, n, visited, src);

    int chk;
    printf("Enter check : 1- connectivity, 2-path checker, 3-No of connected components, 4-check fi strongly connected or weakly\n");
    scanf("%d", chk);
    switch (chk)
    {
    case 1:
        if (connected(adj, n))
            printf("Graph is connected\n");
        else
            printf("Graph is disconnected\n");
        break;
    case 2:
        if (checkPath(adj, n, visited, src, dest))
            printf("There exists a path from %d to %d\n", src, dest);
        else
            printf("There exists no path from %d to %d\n", src, dest);
        break;
    case 3:
        int res = connectedComponent(adj, n);
        printf("No. of connected components %d\n", res);
        break;
    case 4:
        if (stronglyConnected(adj, n))
            printf("Graph is strongly connected\n");
        else
        {
            int b[MAX][MAX] = {0};
            removeEdgeDirection(adj, b, n);
            if (weaklyConnected(b, n))
                printf("Graph is weakly connected\n");
            else
                printf("Graph is disconnected\n");
        }
    }
}
void createGraph(int adj[MAX][MAX], int n)
{
    printf("Enter -1 -1 to stop adding edges\n");
    int src, dest;
    while (1)
    {
        scanf("%d %d", &src, &dest);
        if (src < 0 || dest < 0 || src >= n || dest >= n)
            break;
        adj[src][dest] = 1;
    }
}
void bfs(int adj[MAX][MAX], int n, int visited[MAX], int src)
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
        for (int i = 0; i < n; i++)
        {
            if (adj[src][i] && visited[i] == 0)
            {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
int connected(int adj[MAX][MAX], int n, int visited[MAX])
{
    bfs(adj, n, visited, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            return 0;
    }
    return 1;
}
int checkPath(int adj[MAX][MAX], int n, int visited[MAX], int src, int dest)
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
        for (int i = 0; i < n; i++)
        {
            if (adj[src][i] && visited[i] == 0)
            {
                if (i == dest)
                    return 1;
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    return 0;
}
int connectedComponent(int adj[MAX][MAX], int n, int visited[MAX])
{
    bfs(adj, n, visited, 0);
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            bfs(adj, n, visited, i);
        }
    }
    return count;
}

int stronglyConnected(int adj[MAX][MAX], int n, int visited[MAX])
{
    for (int i = 0; i < n; i++)
    {
        bfs(adj, n, visited, i);
        for (int j = 0; j < n; j++)
        {
            if (visited[i] == 0)
                return 0;
        }
        visited[MAX] = {0};
    }
}
void removeEdgeDirection(int a[MAX][MAX], int b[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                b[i][j] = b[j][i] = 1;
            }
        }
    }
}
int weaklyConnected(int adj[MAX][MAX], int n, int visited[MAX])
{
    connected(adj, n, visited);
}