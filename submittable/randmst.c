#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/* #define V 100*/
int V;
double** graph;
double *oldx;
double *oldy;
double *oldz;
double *olda;

double prim_algo()
{
    int prev[V];    
    double dist[V];     
    bool MST[V];    
 
    for (int i = 0; i < V; i++)
    {
        dist[i] = 999.999;
        MST[i] = false;
    }

    dist[0] = 0.00;
    prev[0] = -1;
   
    for (int count = 0; count < V - 1; count++)
    {
        double min = 999.999;
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
 
        for (int v = 0; v < V; v++)
        {
            if (graph[min_index][v] != 0 && graph[min_index][v] < dist[v] && MST[v] == false) //can't already be in the tree
            {
                prev[v] = min_index;
                dist[v] = graph[min_index][v];
            }
        }
    }
   
    double sump = 0.00;
    for (int i = 1; i < V; i++)
    {
        sump += graph[i][prev[i]];
    }
    return sump;
}

double prim_algo_dim_0()
{
    int prev[V];    
    double dist[V];     
    bool MST[V];  
    for (int i = 0; i < V; i++)
    {
        dist[i] = 999.999;
        MST[i] = false;
    }

    dist[0] = 0.00;
    prev[0] = -1;
    double sum = 0.00;
    double random;
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
            random = (double)rand() / (double)RAND_MAX;
            if (random != 0 && random < dist[v] && MST[v] == false) //can't already be in the tree
            {
                prev[v] = min_index;
                dist[v] = random;
            }
        }
    }
   
    return sum;
}

int main (int argc, char *argv[])
{
    int dimension = 0;

    int vertices = atoi(argv[2]);
	int trials = atoi(argv[3]);
	dimension = atoi(argv[4]);

    if ( dimension < 0 || dimension > 4) {
        printf("Error: dimension should be 0, 2, 3, or 4.\n");
        return -1;
    } else if (dimension == 1) {
        dimension = 0;
    }

    V = vertices;

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
    oldx = malloc (sizeof(double) * V);    
    oldz = malloc (sizeof(double) * V);    
    oldy = malloc (sizeof(double) * V);    
    olda = malloc (sizeof(double) * V);    

    int size = 0;
    double sum = 0;
    srand(time(NULL));

    if (dimension == 0)
    {
        for (int a = 0; a < trials; a++)
        {          
            sum += prim_algo_dim_0();
        }
    }
    else
    {
        for (int a = 0; a < trials; a++)
        {      
            size = 0;
            srand(time(NULL));
            if(dimension == 2)
            {
                for (int i = 0; i < V; i++)
                {
                    oldx[i] = (double)rand() / (double)RAND_MAX;
                    oldy[i] = (double)rand() / (double)RAND_MAX;

                    size++;
                    for (int j = 0; j < size; j++)
                    {
                        graph[i][j] = sqrt((oldx[i]-oldx[j])*(oldx[i]-oldx[j]) + (oldy[i]-oldy[j])*(oldy[i]-oldy[j]));
                        graph[j][i] = graph[i][j];
                    }
                }
            }
            else if(dimension == 3)
            {      
                for (int i = 0; i < V; i++)
                {
                    oldx[i] = (double)rand() / (double)RAND_MAX;
                    oldy[i] = (double)rand() / (double)RAND_MAX;
                    oldz[i] = (double)rand() / (double)RAND_MAX;

                    size++;
                    for (int j = 0; j < size; j++)
                    {
                        graph[i][j] = sqrt((oldx[i]-oldx[j])*(oldx[i]-oldx[j])+ (oldy[i]-oldy[j])*(oldy[i]-oldy[j]) + (oldz[i]-oldz[j])*(oldz[i]-oldz[j]));
                        graph[j][i] = graph[i][j];
                    }
                }    
            } 
            else if(dimension == 4)
            {      
                for (int i = 0; i < V; i++)
                {
                    oldx[i] = (double)rand() / (double)RAND_MAX;
                    oldy[i] = (double)rand() / (double)RAND_MAX;
                    oldz[i] = (double)rand() / (double)RAND_MAX;
                    olda[i] = (double)rand() / (double)RAND_MAX;

                    size++;
                    for (int j = 0; j < size; j++)
                    {
                        graph[i][j] = sqrt((oldx[i]-oldx[j])*(oldx[i]-oldx[j])+ (oldy[i]-oldy[j])*(oldy[i]-oldy[j]) + (oldz[i]-oldz[j])*(oldz[i]-oldz[j]) + (olda[i]-olda[j])*(olda[i]-olda[j]));
                        graph[j][i] = graph[i][j];
                    }
                }          
            }
            sum += prim_algo();
        }
    }
    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    free(oldx);
    free(oldy);
    free(oldz);
    free(olda);  
    printf("%lf %d %d %d\n", sum/trials, V,trials, dimension);
    return 0;
} 
