// DFS traversal for a connected graph
// Adjacency matrix representation

#include <stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX], int n);
void dfs(int adj[MAX][MAX], int n, int visited[MAX], int src);
int checkPath(int adj[MAX][MAX], int n, int visited[MAX], int src, int dest);
int connected(int adj[MAX][MAX], int n, int visited[MAX]);
int connectedComponent(int adj[MAX][MAX], int n, int visited[MAX]); // lil confused in this one
int stronglyConnected(int adj[MAX][MAX], int n, int visited[MAX]);
void removeEdgeDirection(int a[MAX][MAX], int b[MAX][MAX], int n);
int weaklyConnected(int adj[MAX][MAX], int n, int visited[MAX]);

int main()
{
    int n, src;

    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter the no. of vertices\n");
    scanf("%d", &n);

    printf("Enter the adjacency information\n");
    createGraph(adj, n);

    printf("Enter the source vertex\n");
    scanf("%d", &src);

    printf("DFS traversal\n");
    dfs(adj, n, visited, src);

    int chk;
    printf("Wanna check connec : enter 1 : ");
    scanf("%d", &chk);
    if (chk == 1)
    {
        printf("Enter dest :\n");
        int dest;
        scanf("%d", &dest);
        checkPath(adj, n, visited, src, dest);
    }
    chk = 0;
    printf("Wanna check if graph is connected ? : enter 1 : ");
    scanf("%d", &chk);
    if (chk == 1)
    {
        if (connected(adj, n))
            printf("Graph is connected : ");
        else
            printf("Graph is disconnected ");
    }
    chk = 0;
    printf("Wanna check the number of graph comp that r connected ? : enter 1 : ");
    scanf("%d", &chk);
    if (chk == 1)
    {
        int res = connectedComponent(adj, n);
        printf("No. of connected components %d\n", res);
    }
    chk = 0;
    printf("Wanna check if graph is strongly or weakly connected ? : enter 1 : ");
    scanf("%d", &chk);
    if (chk == 1)
    {
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
    int src, dest;
    printf("Enter -1 -1 to stop adding edges\n");
    while (1)
    {
        scanf("%d%d", &src, &dest);
        if (src < 0 || dest < 0 || src >= n || dest >= n)
            break;
        adj[src][dest] = 1;
    }
}

// recursive sol :
void dfs(int adj[MAX][MAX], int n, int visited[MAX], int src)
{
    printf("%d ", src);
    visited[src] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[src][i] && visited[i] == 0)
            dfs(adj, n, visited, i);
    }
}
// // iterative sol :
// void dfs(int adj[MAX][MAX], int n, int visited[MAX], int src)
// {
//     int s[MAX];   // create stack : instead of call stack
//     int top = -1; // init stack.

//     s[++top] = src;
//     visited[src] = 1;
//     printf("%d ", src);

//     int v;
//     while (top != -1) // while stack not emp
//     {
//         v = s[top]; // peek.
//         for (int i = 0; i < n; i++)
//         {
//             if (adj[v][i] && visited[i] == 0) // a neighbour vertex that isnt visited is found.
//                 break;
//         }
//         if (i < n)
//         {
//             s[++top] = i;
//             visited[i] = 1;
//             printf("%d ", i);
//         }
//         else
//             top--; // the excess ele in the stack : ones that are already visited coming after iterating thru the entire i loop : i==n
//     }
// }

int checkPath(int adj[MAX][MAX], int n, int visited[MAX], int src, int dest)
{
    visited[src] = 1;
    for (int i = 0; i < n; i++)
    {
        if (adj[src][i] && !visited[i])
        {
            if (i == dest)
                return 1;
            return checkPath(adj, n, visited, i, dest);
        }
    }
    return 0;
}
int connected(int adj[MAX][MAX], int n, int visited[MAX])
{
    dfs(adj, n, visited, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            return 0;
    }
    return 1;
}
int connectedComponent(int adj[MAX][MAX], int n, int visited[MAX])
{
    int c = 1;
    dfs(adj, n, visited, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0) // lil confused here :
        {
            c++;
            dfs(adj, n, visited, i);
        }
    }
    return c;
}
int stronglyConnected(int adj[MAX][MAX], int n, int visited[MAX])
{
    for (int i = 0; i < n; i++)
    {
        dfs(adj, n, visited, i);
        for (int j = 0; j < n; j++)
        {
            if (visited[i] == 0)
                return 0;
        }
        visited[MAX] = {0};
    }
    return 1;
}
void removeEdgeDirection(int a[MAX][MAX], int b[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1)
                b[i][j] = b[j][i] = 1;
}
int weaklyConnected(int adj[MAX][MAX], int n, int visited[MAX])
{
    connected(adj, n, visited);
}