#include <limits.h> 
#include <stdbool.h> 
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define V 256
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
            if (graph[min_index][v] != 0 && graph[min_index][v] < key[v] && MST[v] == false) 
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
        //printf("%lf\n", sum);

    }
    printf("%lf\n", sum);
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
    double sum = 0;
    srand(time(NULL)); 
    for (int i = 0; i < 5; i++)
    {

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                double x_1 = (double)rand() / (double)RAND_MAX;
                // double y_1 = (double)rand() / (double)RAND_MAX;
                // double x_2 = (double)rand() / (double)RAND_MAX;
                // double y_2 = (double)rand() / (double)RAND_MAX;

                graph[i][j] = x_1;//sqrt((y_2-y_1)*(y_2-y_1) + (x_2-x_1)*(x_2-x_1));
                graph[j][i] = x_1;

                if (i == j)
                {
                    graph[i][j] = 0;
                }
            }   
        }  
        
        prim_algo(); 
    }
    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0; 
} 
