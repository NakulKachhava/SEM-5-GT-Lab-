#include <stdio.h>

int main(int argc, char const *argv[])
{
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
    
    int adm[v][v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adm[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        adm[edges[i][0]][edges[i][1]] = 1;
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d ",adm[i][j]);
        }
        printf("\n");
    }

    return 0;
}
