#include <stdio.h>
#include <math.h>

#define v 6
int adm[v][v];
int visited[v];

void bfs(int src){
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
            if (adm[current][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                que[++rear] = i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int e;

    printf("Enter no. of edges: ");
    scanf("%d",&e);

    int edges[e][2];
    
    int branches[v-1][2];
    int chords[e-v+1][2];

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

    int visited1[v];

    for (int i = 0; i < v; i++)
    {
        visited1[i] = 0;
    }

    visited1[0] = 1;
    que[++rear] = 0;

    int n=0;

    while (front<rear)
    {
        int current = que[++front];
        for (int i=0; i < v; i++){
            if (adm[current][i] == 1 && visited1[i] == 0){
                visited1[i] = 1;
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
        int found = 0;

        for (int j = 0; j < v - 1; j++)
        {
            if ((branches[j][0] == edges[i][0] && branches[j][1] == edges[i][1]) ||
                (branches[j][0] == edges[i][1] && branches[j][1] == edges[i][0]))
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            chords[m][0] = edges[i][0];
            chords[m][1] = edges[i][1];
            m++;
        }
    }

    int fundamentalCutSets[v-1][e-v+2][2];

    int c = 0;

    for (int i = 0; i < v-1; i++)
    {
        for(int j = 0; j < e-v+2; j++){
            fundamentalCutSets[i][j][0] = -1;
            fundamentalCutSets[i][j][1] = -1;
        }
    }

    for (int i = 0; i < v-1; i++)
    {
        for (int j = 0; j < pow(2,e-v+1); j++)
        {
            for (int k = 0; k <= j; k++)
            {
                int adm1[v][v];
                
                int ch[e-v+1][2];
                
                for (int a = 0; a < e-v+1; a++)
                {
                    ch[a][0] = -1;
                    ch[a][1] = -1;
                }
                
                for (int i = 0; i < e; i++)
                {
                    if ((edges[i][0] == branches[i][0] && edges[i][1] == branches[i][1]) || (edges[i][0] == branches[i][1] && edges[i][1] == branches[i][0]) )
                    {
                        continue;
                    }
                    else if (){
                        
                    }
                    else{
                        adm[edges[i][0]][edges[i][1]] = 1;
                        adm[edges[i][1]][edges[i][0]] = 1;
                    }
                }

                int group = 0;

                for (int i = 0; i < v; i++)
                {
                    if (visited[i] == 0)
                    {
                        bfs(i);
                        group++;
                    }
                }

                if (group > 1)
                {
                    fundamentalCutSets[c][0][0] = branches[i][0];
                    fundamentalCutSets[c][0][1] = branches[i][1];
                    
                    for(int b = 0; b < e-v+1; b++){
                        fundamentalCutSets[c][b+1][0] = ch[b][0];
                        fundamentalCutSets[c][b+1][1] = ch[b][1];
                    }
                    
                    c++;
                }
                
            }
        }
    }
    
    return 0;
}
