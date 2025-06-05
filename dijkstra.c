#include <stdio.h>
int minDistance(int dist[10], int included[],int n)
{
    int v,min =999, min_index;
    for (v = 0; v < n; v++)
        if (included[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
void printSolution(int dist[10], int n)
{	int i;
    printf("Vertex Distance from Source\n");
    for (i = 0; i < n; i++)
        printf("\t%d \t\t\t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[10][10], int src, int n)
{
    int dist[n],i,count,v; 
    int included[n]; 
    for (i = 0; i < n; i++)
        dist[i] = 999, included[i] = 0;
    dist[src] = 0;
    for (count = 0; count < n - 1; count++) {
        int u = minDistance(dist, included,n);
        included[u] =1;
        for (v = 0; v < n; v++)
            if (included[v]==0 && graph[u][v] && dist[u] != 999
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, n);
}
void printmatrix(int a[10][10],int n){ 
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int a[10][10], i, j, n,src;
	printf("Enter the number of vertices: "); 
	scanf("%d", &n);
	printf("Enter the adjacency matrix:\n"); 
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("Entered adjacency matrix is:\n"); 
	printmatrix(a,n);
	printf("Enter the source vertex:(Any vertex 0 to n-1)");
	scanf("%d", &src);
	dijkstra(a,src,n);
	return 0;
}
