#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else {
        return queue[front];
        front++;
    }
}

void init(int a, int n){
    
}

int main(int argc, char const *argv[])
{
    int v,e;

    printf("Enter no. of vertices: ");
    scanf("%d",&v);
    printf("Enter no. of edges: ");
    scanf("%d",&e);

    int visited[v];
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

    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        adm[edges[i][0]][edges[i][1]] = 1;
        adm[edges[i][1]][edges[i][0]] = 1;
    }

    enqueue(0);
    visited[0] = 1;

    for (int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            if (visited[i] != 1 && adm[i][j] == 1){
                enqueue(i);
                visited[i] = 1;
            }
            else if (adm[i][j] != 0){
                int ver = dequeue();
                printf("%d",ver);
            }
        }
    }

    return 0;
}

// corrected program is below

int que[5]
rear = -1, front = -1

visited[0] = 1;
que[++rear] = 0;

while (f<r)
{
    int current = que[++fr];
    printf("%d ",current);
    for (int i=0; i < v; i++){
        if (adm[current][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            que[++rear] = i;
        }
    }
}
