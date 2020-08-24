#include<bits/stdc++.h> 
using namespace std; 
void cofactor(int matrix[10][10],int p,int q,int temp[10][10],int n)
{
	int i=0,j=0;
	for(int r=0;r<n;r++)
     {
	   for(int c=0;c<n;c++)
	   {
	   	  if(r!=p&&c!=q)
	   	    {
			   temp[i][j++]=matrix[r][c];
			   if(j==n-1)
			      { j=0;
				   i++;
			     }
	         }
       }
   }
}
int determinant(int matrix[10][10],int n)
{  
   int d=0,temp[10][10],sg=1;
    if(n==1)
      return matrix[0][0];
	for(int f=0;f<n;f++)
	{      cofactor(matrix,0,f,temp,n);
		d+= matrix[0][f]*sg*determinant(temp,n-1);
		sg=-sg;
	}
	
	return d;
}
void adjoint(int matrix[10][10],int adj[10][10],int n)
{  
  if(n==1)
   {
   adj[0][0]=1;
   return;
    }
int temp[10][10],sg=1;
	for(int i=0;i<n;i++)
	{
     	for(int j=0;j<n;j++)
     	{
		    cofactor(matrix,i,j,temp,n);
		    if((i+j)%2==0)
		    sg=1;
		    else
		    sg=-1;
		    adj[j][i]=sg*(determinant(temp,n-1));
        }
   }  
}


int main()
{   

int n,matrix[10][10];
int adj[10][10];
cout<<"Enter size of matrix\n";
cin>>n;

cout<<"Enter matrix\n";
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cin>>matrix[i][j];

  
    adjoint(matrix, adj,n); 
    
int d=determinant(matrix,n);

cout<<"Deteminant of matrix is : "<<d<<endl;

if(d==0)
cout<<"singular matrix\n";
else
{

cout<<"Inverse of matrix is\n";
	for(int i=0;i<n;i++)
      {
	  for(int j=0;j<n;j++)
        cout<<adj[i][j]/float(d)<<" ";
        cout<<"\n";
      }
    
} 

return 0;
}
