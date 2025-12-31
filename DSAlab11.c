/*Develop a Program in C for the following operations on Graph(G) of Cities 
a. Create a Graph of N cities using Adjacency Matrix. 
b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS method*/
#include <stdio.h>
#include <stdlib.h>

int n, a[20][20], visited1[20], visited2[20], source;

void read_data()
{
    int i, j;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void print_data(int visited[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (visited[i])
            printf("Vertex %d is reachable\n", i);
        else
            printf("Vertex %d is NOT reachable\n", i);
    }
}

void BFS()
{
    int q[20], f = 0, r = 0, i, j;
    q[r] = source;
    visited1[source] = 1;

    while (f <= r)
    {
        i = q[f++];
        printf("%d ", i);
        for (j = 0; j < n; j++)
        {
            if (a[i][j] && !visited1[j])
            {
                visited1[j] = 1;
                q[++r] = j;
            }
        }
    }
}

void DFS(int src)
{
    int j;
    visited2[src] = 1;
    printf("%d ", src);
    for (j = 0; j < n; j++)
        if (a[src][j] && !visited2[j])
            DFS(j);
}

int main()
{
    int i, ch;
    read_data();

    while (1)
    {
        printf("\n1.BFS\n2.DFS\n3.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            for (i = 0; i < n; i++) visited1[i] = 0;
            printf("Enter source: ");
            scanf("%d", &source);
            printf("BFS Traversal: ");
            BFS();
            printf("\n");
            print_data(visited1);
            break;

        case 2:
            for (i = 0; i < n; i++) visited2[i] = 0;
            printf("Enter source: ");
            scanf("%d", &source);
            printf("DFS Traversal: ");
            DFS(source);
            printf("\n");
            print_data(visited2);
            break;

        case 3:
            exit(0);
        }
    }
}
