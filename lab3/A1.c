#include <stdio.h>

void main(){
    int v,e;

    printf("Enter no. of vertices: ");
    scanf("%d",&v);
    printf("Enter no. of edges: ");
    scanf("%d",&e);

    int visited[v];
    int edges[e][2];
    int stack[v];
    int top = -1;

    for (int i = 0; i < e; i++)
    {
        printf("Enter edge %d: ",i);
        scanf("%d %d",&edges[i][0],&edges[i][1]);
    }
    
    int adm[v][v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adm[i][j] = 0;
        }
    }

    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        adm[edges[i][0]][edges[i][1]] = 1;
        adm[edges[i][1]][edges[i][0]] = 1;
    }

    stack[++top] = 0;

    while (top != -1)
    {
        int current = stack[top--];
        if (visited[current] == 0)
        {
            printf("%d ",current);
            visited[current] = 1;    
        }

        for (int i = v-1; i >= 0; i--)
        {
            if (adm[current][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
            }
        }
    }
}