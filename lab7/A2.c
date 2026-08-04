#include <stdio.h>
#include <math.h>

#define v 5
int visited[v];

void bfs(int src, int adm[][v]){
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
    int edgeConnectivity = e;

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
        adm[edges[i][1]][edges[i][0]] = 1;
    }

    unsigned int pow_set_size = 1 << e;

    // Run from counter 000..0 to 111..1
    for (int counter = 1; counter < pow_set_size; counter++) {
        int count = 0;
        int adm1[v][v];

        for (int i = 0; i < v; i++)
        {
            for (int k = 0; k < v; k++)
            {
                adm1[i][k] = 0;
            }
        }

        for (int j = 0; j < e; j++) {
            // Check if jth bit in the counter is set
            if (counter & (1 << j)) {
                for (int p = 0; p < v; p++)
                {
                    for (int q = 0; q < v; q++)
                    {
                        if (adm[edges[j][0]][edges[j][1]] == 1)
                        {
                            adm1[edges[j][0]][edges[j][1]] == 0;
                            adm1[edges[j][1]][edges[j][0]] == 0;
                        }
                        else{
                            adm1[p][q] = adm[p][q];
                        }
                    }
                }
                count++;
            }
        }

        int group = 0;

        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0)
            {
                bfs(i, adm1);
                group++;
            }
        }

        if (group > 1)
        {
            if (count < edgeConnectivity)
            {
                edgeConnectivity = count;
            }
        }
    }

    printf("Edge Connectivity: %d",edgeConnectivity);

    return 0;
}