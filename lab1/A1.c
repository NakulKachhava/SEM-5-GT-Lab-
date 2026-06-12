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
        
    for (int i = 0; i < v; i++)
    {
        printf("%d -> ",i);
        for (int j = 0; j < e; j++)
        {
            if(edges[j][0]==i){
                printf("%d",edges[j][1]);
            }
        }
        printf("\n");
    }
    return 0;
}
