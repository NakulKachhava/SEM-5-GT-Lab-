#include <stdio.h>

#define E 5
#define V 6

int edges[][2] = {
    {0, 3},
    {0, 4},
    {1, 4},
    {1, 5},
    {2, 5}
};

int combinations[32][5] = {
    {-1,-1,-1,-1,-1},

    {0,-1,-1,-1,-1},
    {1,-1,-1,-1,-1},
    {2,-1,-1,-1,-1},
    {3,-1,-1,-1,-1},
    {4,-1,-1,-1,-1},

    {0,1,-1,-1,-1},
    {0,2,-1,-1,-1},
    {0,3,-1,-1,-1},
    {0,4,-1,-1,-1},
    {1,2,-1,-1,-1},
    {1,3,-1,-1,-1},
    {1,4,-1,-1,-1},
    {2,3,-1,-1,-1},
    {2,4,-1,-1,-1},
    {3,4,-1,-1,-1},

    {0,1,2,-1,-1},
    {0,1,3,-1,-1},
    {0,1,4,-1,-1},
    {0,2,3,-1,-1},
    {0,2,4,-1,-1},
    {0,3,4,-1,-1},
    {1,2,3,-1,-1},
    {1,2,4,-1,-1},
    {1,3,4,-1,-1},
    {2,3,4,-1,-1},

    {0,1,2,3,-1},
    {0,1,2,4,-1},
    {0,1,3,4,-1},
    {0,2,3,4,-1},
    {1,2,3,4,-1},

    {0,1,2,3,4}
};

int arr[32];
int p = 0;

void printMatching(int index)
{
    int j;

    printf("{ ");

    for(j = 0; j < E; j++)
    {
        if(combinations[index][j] != -1)
        {
            printf("%d ", combinations[index][j]);
        }
    }

    printf("}");
}

void findMatching()
{
    int i, j, k;
    int x;
    int flag = 0;
    int freq[V];

    for (i = 0; i < V; i++)
    {
        freq[i] = 0;
    }
    
    for (i = 0; i < 32; i++)
    {
        flag = 0;
        for (x = 0; x < V; x++)
        {
            freq[x] = 0;
        }
        for (j = 0; j < 5; j++)
        {
            if (combinations[i][j] != -1)
            {
                freq[edges[combinations[i][j]][0]] += 1;
                freq[edges[combinations[i][j]][1]] += 1;
            }
            
        }
        for (k = 0; k < V; k++)
        {
            if (freq[k] > 1)
            {
                flag = 1;
            }
        }
        if (flag != 1)
        {
            printMatching(i);
        }
    }
}

void findMaximalMatching()
{
    int i, j, e;
    int index;
    int edgeIndex;
    int start, end;
    int freq[V];
    int maximal;

    //code for Find Maximal Matching
}

void findMaximumMatching()
{
	int i, j, k;
    int x;
    int flag = 0;
    int freq[V];
    int size;
    int maxSize = 0;

    for (i = 0; i < V; i++)
    {
        freq[i] = 0;
    }
    
    for (i = 0; i < 32; i++)
    {
        flag = 0;
        for (x = 0; x < V; x++)
        {
            freq[x] = 0;
        }
        for (j = 0; j < 5; j++)
        {
            if (combinations[i][j] != -1)
            {
                freq[edges[combinations[i][j]][0]] += 1;
                freq[edges[combinations[i][j]][1]] += 1;
            }
            
        }
        for (k = 0; k < V; k++)
        {
            if (freq[k] > 1)
            {
                flag = 1;
            }
        }
        if (flag != 1)
        {
            size = i;
        }
        if (maxSize < size)
        {
            maxSize = size;
        }
    }
	
    printMatching(maxSize);
}

void main()
{
    printf("Matching Sets: ");
    findMatching();

    printf("\nMaximal Matching: ");
    findMaximalMatching();

    printf("\nMaximum Matching: ");
    findMaximumMatching();
}
