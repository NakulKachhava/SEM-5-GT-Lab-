#include <stdio.h>
#include <math.h>

#define v 4
int adm[v][v];

int isDominating(int a[], int size){
    int visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        visited[a[i]] = 1;
        for (int j = 0; j < v; j++)
        {   
            if (visited[i] == 0 && adm[a[i]][j] == 1)
            {
                visited[j] = 1;
            }    
        }       
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

void main(){
    int e;

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
        for (int j = 0; j < v; j++)
        {
            adm[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        adm[edges[i][0]][edges[i][1]] = 1;
        adm[edges[i][1]][edges[i][0]] = 1;
    }

    for (int i = 1; i <= v; i++)
    {
        int set[i];

        
        
        if (isDominating(set,i))
        {
            for (int j = 0; j < i; j++)
            {
                printf("%d,",set[i]);
            }
        }
        printf("\n");
    }
}