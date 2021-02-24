#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define V 65536
double** graph;


//double graph[V][V];


double prim_algo()
{

    int prev[V];
    double key[V]; //distance from vertex to source
    bool MST[V];
 
    for (int i = 0; i < V; i++)
    {
        key[i] = 999.999;
        MST[i] = false;
    }

    key[0] = 0.00;
    prev[0] = -1;
   
    for (int count = 0; count < V - 1; count++)
    {
        double min = 999.999;
        int min_index;

        for (int v = 0; v < V; v++)
        {
            if (key[v] < min && MST[v] == false)
            {
                min = key[v];
                min_index = v;
            }
        }
        MST[min_index] = true;
 
        for (int v = 0; v < V; v++)
        {
            if (graph[min_index][v] != 0 && graph[min_index][v] < key[v] && MST[v] == false) //can't already be in the tree
            {
                prev[v] = min_index;
                key[v] = graph[min_index][v];
            }
        }
    }
   
    double sum = 0.00;
    for (int i = 1; i < V; i++)
    {
        sum += graph[i][prev[i]];
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

    oldx = malloc (sizeof(double) * V);    
    oldz = malloc (sizeof(double) * V);    
    oldy = malloc (sizeof(double) * V);    
 
    int size = 0;
    double sum = 0;
    srand(time(NULL));
    for (int a = 0; a < 10; a++)
    {
        for (int i = 0; i < V; i++)
        {
            oldx[i] = (double)rand() / (double)RAND_MAX;
            //oldy[i] = (double)rand() / (double)RAND_MAX;
            //oldz[i] = (double)rand() / (double)RAND_MAX;
            //olda[i] = (double)rand() / (double)RAND_MAX;
                 
            size++;

            for (int j = 0; j < size; j++)
            {
                graph[i][j] = sqrt((oldx[i]-oldx[j])*(oldx[i]-oldx[j])); //+ (oldy[i]-oldy[j])*(oldy[i]-oldy[j]) + (oldz[i]-oldz[j])*(oldz[i]-oldz[j]));
                graph[j][i] = graph[i][j];
            }
        }

        for(int z = 0; z < V; z++)
        {
            for(int k = 0; k < V; k++)
            {
                //printf("%lf\n", graph[z][k]);
            }
        }
           
        sum += prim_algo();
        size = 0;
    }
    printf("%lf\n", sum/10);

    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0;
} 
