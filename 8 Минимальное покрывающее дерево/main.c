#include<stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, numb_element = 1, min, a, b, min_cost = 0;
    int V, x, y, z, m;
    printf("Enter the number of vertices: "); //ввести количество вершин графа
    scanf("%d", &V);
    printf("\nEnter the number of edges: "); //ввести количество ребер графа
    scanf("%d", &m);
    int **graph = (int**)malloc(V * sizeof(int *));
    int *visited = (int*)malloc(V * sizeof(int *));
    for(i = 1; i <= V; i++)
    {
        graph[i] = (int *)malloc(V*sizeof(int));
        visited[i] = 0;
    }
    for (i = 1; i <= V; i++)
        for (j = 0; j < V; j++)
            graph[i][j] = 10000;
    if (m != 0)
        printf("\nEnter the list of edges: \n"); //ввести список графа: вершина, вершина, с которой она связана ребром, и вес этого ребра
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        if (x > V || y > V)
        {
            printf("Error!\n");
            free(visited);
            for (i = 0; i < V; i++)
            {
                free(graph[i]);
            }
            free(graph);
            return 0;
        }
        graph[x][y] = z;
        graph[y][x] = z;
    }

    visited[1] = 1; //посетили первую вершину
    while(numb_element < V)
    {
        min = 10000;
        //в каждом цикле ищем минимальный вес
        for(i = 1; i <= V; i++)
        {
            for(j = 1; j <= V; j++)
            {
                if(graph[i][j] < min)
                {
                    if(visited[i] != 0)
                    {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if(visited[b] == 0) //если узел не был посещен
        {
            printf("\n%d to %d:  cost = %d", a, b, min);
            min_cost = min_cost + min;
            numb_element++;
        }
        visited[b] = 1;
        graph[a][b] = graph[b][a] = 10000;
    }
    printf("\nMinimum weight is %d", min_cost);
    free(visited);
    for (i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
