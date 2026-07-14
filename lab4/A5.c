#include <stdio.h>

#define v 3
int adm[v][v];
int dist[v][v];

void bfs(int src){
    int que[v];


    int rear = -1, front = -1;

    int visited[v];

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
                dist[src][i] = dist[src][current] + 1;
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

    int visited[v];
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

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            dist[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        adm[edges[i][0]][edges[i][1]] = 1;
        adm[edges[i][1]][edges[i][0]] = 1;
    }

    for (int i = 0; i < v; i++)
    {
        bfs(i);
    }

    int eccentricity[v];
    
    for (int i = 0; i < v; i++)
    {
        int max_dist = dist[i][0];
        for (int j = 0; j < v; j++)
        {
            if (max_dist < dist[i][j])
            {
                max_dist = dist[i][j];
            }
        }
        eccentricity[i] = max_dist;
    }
    
    int minecc = eccentricity[0];
    int c1, c2;

    for (int i = 0; i < v; i++)
    {
        if (eccentricity[i] < minecc)
        {
            minecc = eccentricity[i];
            c1 = i;
        }
        
        if (eccentricity[i] == minecc)
        {
            c2 = i;
        }
        
    }

    if (c1 != c2)
    {
        printf("Centers of the Tree: %d %d",c1,c2);    
    }
    else{
        printf("Center of the Tree: %d",c1);
    }

    return 0;
}