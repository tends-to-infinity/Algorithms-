#include<bits/stdc++.h>
using namespace std;

void display(int dist[],int V) 
{ 
          cout<<"Vertex \t\t Distance from Source\n"; 
    for (int i = 0; i < V; i++) 
         cout<<i<<" \t\t "<<dist[i]<<endl;
} 

int shortestDistance(int dist[], bool S[],int V) 
{ 
	
	int min = INT_MAX, indexofmin; 

	for (int w=0;w<V;w++) 
		if (S[w] == false && dist[w] <= min) 
		  {
			  min = dist[w];
			   indexofmin = w; 
          	}

	return indexofmin; 
} 
 
void dijkstra(int graph[][1000], int source,int V) 
{ 
	int dist[V]; 
    bool S[V]; 

	for (int i=0;i<V;i++) 
	{
		dist[i] = INT_MAX;
         S[i] = false; 

     }
	dist[source] = 0; 

 
	for (int i = 0; i < V - 1; i++) 
	{  
		int u = shortestDistance(dist,S,V); 
       
	   S[u] = true; 

	 for (int v = 0; v < V; v++) 
         	if (!S[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
				  dist[v] = dist[u] + graph[u][v]; 
	} 
	display(dist,V); 
}
int main() 
{ 
   int V ;
   cout<<"Enter number of vertices:";
   cin>>V;
   cout<<"Enter adjacency list:"<<endl;
   int graph[V][1000];
  for(int i=0;i<V;i++)
   {
   	for(int j=0;j<V;j++)
     	{
   		    cin>>graph[i][j];
	    }
   }
	
	dijkstra(graph, 0,V); 

	return 0; 
} 

