
#include <limits.h> 
#include <stdbool.h> 
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define V 10
double** graph;


//double graph[V][V];

double sumx = 0;

int minKey(int key[], bool mstSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min && key[v] != 0 ) 
            min = key[v], min_index = v; 
  
    return min_index; 
} 

double prim_algo() 
{ 

    int prev[V]; 
    int key[V]; //distance from vertex to source
    bool MST[V]; 
  
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        MST[i] = false; 
    }

    key[0] = 0; 
    prev[0] = -1;
    
    for (int count = 0; count < V - 1; count++) 
    { 
        int min = INT_MAX; 
        int min_index; 

        // for (int v = 0; v < V; v++)
        // {
        //     if (key[v] < min && MST[v] == false) 
        //     {
        //         min = key[v];
        //         min_index = v; 
        //     }
        // } 

        min_index = minKey(key, MST);
        printf("%d\n", min_index);
        MST[min_index] = true; 
  
        for (int v = 0; v < V; v++) 
        {
            if (graph[min_index][v] != 0 && graph[min_index][v] < key[v] && MST[v] == false) //can't already be in the tree
            {
                prev[v] = min_index; 
                key[v] = graph[min_index][v]; 
                // sumx += key[v];
                // printf("%lf\n", sumx);
                //printf("%d\n", key[v]);
            }
            
        }
    } 

    double sum = 0; //- transferred to global
    for (int i = 1; i < V; i++) 
    {
        sum += graph[i][prev[i]];
        //printf("%lf\n", sum);

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
    double oldx[V]; 
    double oldy[V];  
    double oldz[V];    
    int size = 0;
    double sum = 0;
    srand(time(NULL));
    for (int a = 0; a < 10; a++)
    { 
        for (int i = 0; i < V; i++)
        {
            oldx[i] = (double)rand() / (double)RAND_MAX;
            //printf("%lf\n", oldx[i]);
            //oldy[i] = (double)rand() / (double)RAND_MAX;
            //oldz[i] = (double)rand() / (double)RAND_MAX;
            //olda[i] = (double)rand() / (double)RAND_MAX;
                 
            size++;

            for (int j = 0; j < size; j++)
            {
                graph[i][j] = sqrt((oldx[i]-oldx[j])*(oldx[i]-oldx[j])); //+ (oldy[i]-oldy[j])*(oldy[i]-oldy[j]) + (oldz[i]-oldz[j])*(oldz[i]-oldz[j]));
                graph[j][i] = graph[i][j];
                //printf("%lf\n", graph[j][i]);
            }
        }

        // for(int z = 0; z < V; z++)
        // {
        //     for(int k = 0; k < V; k++)
        //     {
        //         printf("%lf\n", graph[z][k]);
        //     }
        // }
            
        sum += prim_algo(); 
        size = 0;
        
    }
    printf("%lf\n", sum/10);
    printf("%lf\n", sumx/10);

    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0; 
} 
