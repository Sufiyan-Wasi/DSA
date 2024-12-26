#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 10 
 
int graph[MAX][MAX]; 
int visited[MAX]; 
int queue[MAX]; 
int front = -1, rear = -1; 
void createGraph(int n) 
{ 
    int i, j; 
    printf("Enter the adjacency matrix:\n");                                              
    for (i = 0; i < n; i++) 
    { 
        printf("Enter row %d: ", i + 1); 
        for (j = 0; j < n; j++) 
        {   
            scanf("%d", &graph[i][j]);  
        } 
    } 
} 
void DFS(int start, int n) 
{ 
    int i; 
    printf("%d ", start); 
    visited[start] = 1; 
    for (i = 0; i < n; i++) 
    { 
        if (!visited[i] && graph[start][i] == 1) 
        { 
            DFS(i, n); 
        } 
    } 
} 
void BFS(int start, int n) 
{ 
    int i, vertex; 
    printf("%d ", start); 
    visited[start] = 1;
    queue[++rear] = start;
    while (front <= rear) 
    { 
        vertex = queue[front++]; 
        for (i = 0; i < n; i++) 
        { 
            if (!visited[i] && graph[vertex][i] == 1) 
            { 
                printf("%d ", i); 
                visited[i] = 1; 
                queue[++rear] = i;
            } 
        } 
    } 
} 
int main() 
{ 
    int ch,i; 
    int n, start; 
    while (1) 
    { 
        printf("\n1.Create a Graph\n.2.DFS \n 3.BFS \n 4.Exit \n Enter your choice:\n"); 
        scanf("%d", &ch); 
        switch (ch) 
        { 
        case 1: 
            printf("Enter the number of cities: "); 
            scanf("%d", &n); 
            createGraph(n); 
            break; 
        case 2: 
            printf("\nEnter the starting node: "); 
            scanf("%d", &start); 
            printf("\nNodes reachable from node %d using DFS: ", start); 
            DFS(start, n); 
            for (i = 0; i < n; i++) 
            { 
                visited[i] = 0; 
            } 
            break; 
        case 3:front = rear = -1; 
               printf("\nNodes reachable from node %d using BFS: ", start); 
               BFS(start, n); 
           
            for (i = 0; i < n; i++) 
            { 
                visited[i] = 0; 
            } 
 
            printf("\n"); 
        case 4:exit(0); 
            break; 
        } 
    } 
   return 0; 
} 