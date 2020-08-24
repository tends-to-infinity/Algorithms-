#include<bits/stdc++.h>
using namespace std;
int main()
{  
int n,m,p,q;
cout<<"enter size of matrix1\n";
cin>>n>>m;

int matrix1[n][m];
cout<<"enter matrix1\n";
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
cin>>matrix1[i][j];

cout<<"enter size of matrix2\n";
cin>>p>>q;
int matrix2[p][q];
cout<<"enter matrix2\n";
for(int i=0;i<p;i++)
for(int j=0;j<q;j++)
cin>>matrix2[i][j];

if(m!=p)
cout<<"matrix multiplication is not possible\n";
else
{    int x, i, j; 
    int res[n][q]; 
    for (i=0;i<n;i++)  
    { 
        for (j=0;j<q;j++)  
        { 
            res[i][j] = 0; 
            for (x=0;x<m;x++)  
            { 
                res[i][j]+= matrix1[i][x] * matrix2[x][j]; 
            } 
        } 
    } 
    cout<<"resultant matrix is:\n";
    for (i=0;i<n;i++)  
    { 
        for (j=0;j<q;j++)  
        { 
            cout<<res[i][j]<< " "; 
        } 
        cout << "\n"; 
    } 
} 
return 0;
}
