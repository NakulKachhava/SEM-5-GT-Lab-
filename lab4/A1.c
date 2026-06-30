#include <stdio.h>

void main(){
    int v,e;

    printf("Enter no. of vertices: ");
    scanf("%d",&v);
    printf("Enter no. of edges: ");
    scanf("%d",&e);

    int edges[e][2];

    for (int i = 0; i < e; i++)
    {
        printf("Enter edge %d: ",i);
        scanf("%d %d",&edges[i][0],&edges[i][1]);
    } 

    int degree[v];

    for (int i = 0; i < v; i++)
    {
        degree[i] = 0;
    }
    

    for (int i = 0; i < e; i++)
    {
        degree[edges[i][0]] += 1;
        degree[edges[i][1]] += 1;
    }
    
    for (int i = 0; i < v; i++)
    {
        if (degree[i] == 1)
        {
            printf("%d ",i);
        }
    }
}