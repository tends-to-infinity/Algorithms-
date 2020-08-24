#include <bits/stdc++.h> 
using namespace std; 

int find(int parent[], int i) 
{ 
	while (parent[i] != i) 
		i = parent[i]; 
	return i; 
} 

void union1(int i, int j,int parent[]) 
{ 
	int a = find(parent,i); 
	int b = find(parent,j); 
	parent[a] = b; 
} 

int main() 
{ 

			int V;
			cout<<"enter no. of vertices:";
			cin>>V;
	        
	        int cost[V][V];
          	cout<<"enter adjacency matrix: ";

 	for(int i=0;i<V;i++)
	for(int j=0;j<V;j++)
	cin>>cost[i][j];
	
	for(int i=0;i<V;i++)
	for(int j=0;j<V;j++)
	  if(cost[i][j]==0)
	  cost[i][j]=INT_MAX;


		int mincost = 0; 
        int parent[V];

	for (int i = 0; i < V; i++) 
		parent[i] = i; 


	int edge_count = 0; 
	while (edge_count < V - 1) { 
		int min = INT_MAX, a = -1, b = -1; 
		for (int i = 0; i < V; i++) { 
			for (int j = 0; j < V; j++) { 
				if (find(parent,i) != find(parent,j) && cost[i][j] < min) { 
					min = cost[i][j]; 
					a = i; 
					b = j; 
				} 
			} 
		} 

		union1(a, b,parent); 
		printf("Edge %d:(%d, %d) cost:%d \n", 
			edge_count++, a, b, min); 
		mincost += min; 
	} 
	printf("\n Minimum cost= %d \n", mincost); 

	return 0; 
} 

