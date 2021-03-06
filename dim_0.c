#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define V 262144
double** graph;

double prim_algo()
{

    int prev[V];
    double dist[V]; //distance from vertex to source
    bool MST[V];
 
    for (int i = 0; i < V; i++)
    {
        dist[i] = 999.999;
        MST[i] = false;
    }

    dist[0] = 0.00;
    prev[0] = -1;
    double sum = 0.00;
    double random, random2;
    double min = 999.999;
    for (int count = 0; count < V - 1; count++)
    {
        min = 999.999;
        int min_index;

        for (int v = 0; v < V; v++)
        {
            if (dist[v] < min && MST[v] == false)
            {
                min = dist[v];
                min_index = v;
            }
        }
        MST[min_index] = true;
        sum += min;

        for (int v = 0; v < V; v++)
        {
            random2 = (double)rand() / (double)RAND_MAX;
            if (random2 != 0 && random2 < dist[v] && MST[v] == false) //can't already be in the tree
            {
                prev[v] = min_index;
                dist[v] = random2;
            }
        }
    }
   
    return sum;
    //printf("%lf\n", sum);
}

int main()
{
    printf("%d\n",V);

    graph = malloc(V * sizeof(graph[0]));
    if (graph == NULL)
    {
        return 1;
    }
    for (int i = 0; i < V; i++)
    {
        graph[i] = malloc(V * sizeof(graph[0]));
        if (graph[i] == NULL)
        {
            return 1;
        }

    }
    //CREATE GRAPHS
    //double sum = 0;
    double *oldx;
    double *oldy;
    double *oldz;
    double *olda;

    oldx = malloc (sizeof(double) * V);    
    oldz = malloc (sizeof(double) * V);    
    oldy = malloc (sizeof(double) * V);    
    olda = malloc (sizeof(double) * V);    

    int dimension = 0;

    int size = 0;
    double sum = 0;
    srand(time(NULL));
    for (int a = 0; a <5; a++)
    {           
        sum += prim_algo();
        printf("%lf\n", sum);
    }
    printf("%lf\n", sum/5);

    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0;
} 
