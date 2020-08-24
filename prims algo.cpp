#include<iostream>
using namespace std;

int main()
{
	int v;
	cout<<"Enter no. of vertices: ";
	cin>>v;
	
	int g[v][v];
	 
    cout<<"enter adjacency matrix: ";
	for(int i=0;i<v;i++)
	for(int j=0;j<v;j++)
	cin>>g[i][j];
	
    int	s[v] , p[v]  ,cost[v];
    
    for(int i=0;i<v;i++)
      {   
	          cost[v]=INT_MAX ;
	          s[i]=0;
      }
      
    cost[0]=0;
    s[0]=1;
    
    for(int i=0;i<v-1;i++)
    {
    	int min=INT_MAX , indexofmin;
    	for(int u=0;u<v;u++)
    	{
    		if(!s[u]&&cost[u]<min)
    		 {
			    min=cost[u];
		     	    indexofmin=u;
		       }
       	}
       	
       int w=indexofmin;
        s[w]=1;
        
       for(int u=0;u<v;u++)
       {
       	  if(s[u]==0&&g[w][u]&&g[w][u]<cost[u])
       	    {
			   p[u]=w;
			   cost[u]=g[w][u];
	      	}
	   }
	   
    }
       int ans=0;
     for(int i=1;i<v;i++)
	 {           cout<<p[i]<<" --- "<<i<<" \t"<<g[i][p[i]]<<" \n"; 
		               ans = ans+g[i][p[i]];
     }
     
     cout<<"Cost of minimun spanning tree is: "<<ans;
	  	 	
}
