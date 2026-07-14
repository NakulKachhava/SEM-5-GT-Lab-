#include <stdio.h>

#define v 6
int adm[v][v];
int visited[v];

void bfs(int src,int removedVertex){
    int que[v];

    int rear = -1, front = -1;


    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    visited[src] = 1;
    que[++rear] = src;

    while (front<rear)
    {
        int current = que[++front];
        for (int i=0; i < v; i++){
            if (adm[current][i] == 1 && visited[i] == 0 && current != removedVertex){
                visited[i] = 1;
                que[++rear] = i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int i = 0;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adm[i][j] = 0;
        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("Enetr the Element (%d,%d): ",i,j);
            scanf("%d",&adm[i][j]);
        }
    }

    printf("Articulation Points: ");

    for (int r = 0; r < v; r++)
    {
        int group = 0;
        
        for (int i = 0; i < v; i++)
        {
            visited[i] = 0;
        }
        
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0 && i != r)
            {
                bfs(i,r);
                group++;
            }
        }    

        if (group>1)
        {
            printf("%d ",r);       
        }
    }
    
    return 0;
}