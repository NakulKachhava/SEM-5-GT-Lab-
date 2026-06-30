#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int degree[MAX];
int dist[MAX][MAX];
int visited[MAX];
int queue[MAX];
int V;

void bfs(int src)
{
    int front = 0, rear = 0;

    for(int i = 0; i < V; i++)
    {
        visited[i] = 0;
        dist[src][i] = -1;
    }

    visited[src] = 1;
    dist[src][src] = 0;
    queue[rear++] = src;

    while(front < rear)
    {
        int u = queue[front++];

        for(int v = 0; v < V; v++)
        {
            if(graph[u][v]==1 && visited[v] == 0)
            {
                visited[v] = 1;
                dist[src][v] = dist[src][u] + 1;
                queue[rear++] = v;
            }
        }
    }
}

int main()
{
    int E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v):\n");
    for(int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // 1. Find Degree of Each Vertex
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(graph[i][j])
                degree[i]++;
        }
    }

    printf("\nDegree of Each Vertex\n");
    for(int i = 0; i < V; i++)
        printf("Vertex %d : %d\n", i, degree[i]);

    // 2. Identify Pendent Vertices
    printf("\nPendent Vertices\n");
    for(int i = 0; i < V; i++)
    {
        if(degree[i] == 1)
            printf("%d ", i);
    }

    // 3. Find Distance Between Vertices
    for(int i = 0; i < V; i++)
        bfs(i);

    printf("\n\nDistance Matrix\n");
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }

    // 4. Find Eccentricity of Each Vertex
    int ecc[MAX];
    int radius = MAX;

    printf("\nEccentricity\n");
    for(int i = 0; i < V; i++)
    {
        ecc[i] = 0;
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] > ecc[i])
                ecc[i] = dist[i][j];
        }

        printf("Vertex %d : %d\n", i, ecc[i]);

        if(ecc[i] < radius)
            radius = ecc[i];
    }

    // 5. Find Center of the Tree
    printf("\nCenter of Tree\n");
    for(int i = 0; i < V; i++)
    {
        if(ecc[i] == radius)
            printf("%d ", i);
    }

    // 6. Verify Whether Graph is a Tree
    printf("\n\nVerification\n");

    int connected = 1;

    for(int i = 0; i < V; i++)
    {
        if(dist[0][i] == -1)
        {
            connected = 0;
            break;
        }
    }

    if(E == V - 1 && connected)
        printf("Graph is a Tree\n");
    else
        printf("Graph is Not a Tree\n");

    return 0;
}