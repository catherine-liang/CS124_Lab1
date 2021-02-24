#include <limits.h> 
#include <stdbool.h> 
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>


#define V 16384
double** graph;
//double graph[V][V];


void prim_algo() 
{ 

    int prev[V]; 
    int key[V]; 
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
            if (graph[min_index][v] < key[v] && graph[min_index][v] && MST[v] == false) 
            {
                prev[v] = min_index; 
                key[v] = graph[min_index][v]; 
            }
        }
    } 
    
    double sum = 0;
    for (int i = 1; i < V; i++) 
    {
        sum += graph[i][prev[i]];
    }
    printf("%lf\n", sum);
}
  
int main() 
{ 
    printf("%d\n",V);
    graph = malloc(V * sizeof(*graph));
    if (graph == NULL) 
    {
        printf("Malloc Failed!");
    }

    for (int i = 0; i < V; i++)
    {
        graph[i] = malloc(V * sizeof(graph[0]));
        if (graph[i] == NULL) 
        {
            printf("Malloc Failed!");
        }

    }

    srand(time(NULL)); 
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = (double)rand() / (double)RAND_MAX;
        }
    }  

    prim_algo(); 
    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0; 
} 