#include <stdio.h>

int main(int argc, char const *argv[])
{
    int v, e;

    int branches[v-1][2];
    int chords[e-v+1][2];

    printf("Enter no. of vertices: ");
    scanf("%d",&v);

    printf("Enter no. of edges: ");
    scanf("%d",&e);

    int edges[e][2];
    int adm[v][v];
    
    for (int i = 0; i < e; i++)
    {
        printf("Enter edge %d: ",i);
        scanf("%d %d",&edges[i][0],&edges[i][1]);
    }

    for (int i = 0; i < v-1; i++)
    {
        branches[i][0] = 0;
        branches[i][1] = 0;
    }

    for (int i = 0; i < e-v+1; i++)
    {
        chords[i][0] = 0;
        chords[i][1] = 0;
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

    int que[v];

    int rear = -1, front = -1;

    int visited[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    visited[0] = 1;
    que[++rear] = 0;

    int n=0;

    while (front<rear)
    {
        int current = que[++front];
        for (int i=0; i < v; i++){
            if (adm[current][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                que[++rear] = i;
                branches[n][0] = current;
                branches[n][1] = i;
                n++;
            }
        }
    }
    
    int m = 0;

    for (int i = 0; i < e; i++)
    {
        if (branches[i][0] != edges[i][0] && branches[i][1] != edges[i][1])
        {
            chords[m][0] = edges[i][0];
            chords[m][1] = edges[i][1];
            m++;
        }
    }
    
    printf("Branches:\n");
    for (int i = 0; i < v-1; i++)
    {
        printf("(%d,%d)\n",branches[i][0],branches[i][1]);
    }

    printf("Chords:\n");
    for (int i = 0; i < e-v+1; i++)
    {
        printf("(%d,%d)\n",chords[i][0],chords[i][1]);
    }
    
    return 0;
}