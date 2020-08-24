#include<bits/stdc++.h>
using namespace std; 
 
vector<vector<int> > addMatrix(vector<vector<int> > a, vector<vector<int> > b)
 {     vector<vector<int> > ans(a.size());   
   for(int i=0;i<a.size();i++)    
    {     
	       ans[i].resize(a.size());  
         for(int j=0;j<a.size();j++)       
	       ans[i][j] = a[i][j] + b[i][j];  
		      }   
			  
			    return ans; } 
 
vector<vector<int> > diffMatrix(vector<vector<int> > a, vector<vector<int> > b)
 {     vector<vector<int> > ans(a.size());  
    for(int i=0;i<a.size();i++)   
	  {
        ans[i].resize(a.size());      
		   for(int j=0;j<a.size();j++)        
		        ans[i][j] = a[i][j] - b[i][j];  
				   }   
				     return ans; } 
 
vector<vector<int> > subMatrix(vector<vector<int> > parent, int quad)
 {    
  int r,c;     
  if(quad == 1)r = 0, c = 0;  
     else if(quad == 2)r = 0, c = parent.size()/2;   
	   else if(quad == 4)r = parent.size()/2, c = parent.size()/2;    
	    else if(quad == 3)r = parent.size()/2, c = 0; 
 
    vector<vector<int> > ans(parent.size()/2);    
	 for(int i=r;i<r + parent.size()/2;i++)  
	    {         ans[i-r].resize(parent.size()/2);       
		     for(int j=c; j < c + parent.size()/2; j++)        
		       ans[i-r][j-c] = parent[i][j];   
			     }    
			    return ans; 
} 
 
void assignsubMatrix(vector<vector<int> > &parent,vector<vector<int> > sub, int quad)
 {     int r,c;    
      if(quad == 1)r = 0, c = 0;   
    else if(quad == 2)r = 0, c = parent.size()/2;     
	else if(quad == 4)r = parent.size()/2, c = parent.size()/2;   
	  else if(quad == 3)r = parent.size()/2, c = 0; 
 
    for(int i=r;i<r + parent.size()/2;i++) 
	    {         for(int j=c; j < c + parent.size()/2; j++)        
		     parent[i][j] = sub[i-r][j-c];  
			    } 
			 } 
 
vector<vector<int> > strassen(vector<vector<int> > mat1, vector<vector<int> > mat2)
 {     if(mat1.size()==1)  
            {         vector<vector<int> > ans; 
        ans = mat1;      
		   ans[0][0]*=mat2[0][0];    
		        return ans;    
				 }    
 vector<vector<int> > a,b,c,d,e,f,g,h,p1,p2,p3,p4,p5,p6,p7,ans,quad1,quad2,quad3,quad4;    
a = subMatrix(mat1,1); 
b = subMatrix(mat1,2); 
c = subMatrix(mat1,3);  
d = subMatrix(mat1,4); 
e = subMatrix(mat2,1); 
f = subMatrix(mat2,2);   
g = subMatrix(mat2,3);  
h = subMatrix(mat2,4); 
p1 = strassen(a,diffMatrix(f,h));   
p2 = strassen(addMatrix(a,b),h);   
p3 = strassen(addMatrix(c,d),e);  
p4 = strassen(d,diffMatrix(g,e));  
p5 = strassen(addMatrix(a,d),addMatrix(e,h));  
p6 = strassen(diffMatrix(b,d),addMatrix(g,h));  
p7 = strassen(diffMatrix(a,c),addMatrix(e,f)); 
ans.resize(mat1.size());  
for(int i=0;i<mat1.size();i++)
ans[i].resize(mat1.size()); 
quad1 = addMatrix(p4,p5);  
quad1 = addMatrix(quad1,p6);    
quad1 = diffMatrix(quad1,p2);  
quad2 = addMatrix(p1,p2);   
quad3 = addMatrix(p3,p4);    
quad4 = addMatrix(p1,p5);    
quad4 = diffMatrix(quad4,p3);    
quad4 = diffMatrix(quad4,p7);    
assignsubMatrix(ans,quad1,1);   
assignsubMatrix(ans,quad2,2);   
assignsubMatrix(ans,quad3,3);   
assignsubMatrix(ans,quad4,4);   
 return ans; 
						 } 
 
int main() {  

 /* srand(time(NULL));
    int m=1000;
     
     int a[m];
    for(int i=0;i<m;i++)
      a[i]=rand()%m; */
   int n;  
   cout<<"Enter the size of the array - ";     
   cin>>n;   
     vector<vector<int> > mat1(n), mat2(n);    
	       cout<<"Enter first matrix - \n";    
		    for(int i=0;i<n;i++) 
              {         mat1[i].resize(n);    
                 	     for(int j=0;j<n;j++)  
						             cin>>mat1[i][j]; 
									     } 
 
cout<<"Enter second matrix - \n";   
	  for(int i=0;i<n;i++)    
	   {         mat2[i].resize(n);    
	           for(int j=0;j<n;j++)        
			        cin>>mat2[i][j];   
	  }  
	
    double time_spent=0.0;
    clock_t begin = clock();
     vector<vector<int> > multiplied = strassen(mat1,mat2);    
				 cout<<"\nAnswer is - \n";   
				   for(int i=0;i<n;i++)    
				    {         for(int j=0;j<n;j++)
					                cout<<multiplied[i][j]<<" ";
						                  cout<<endl;    
					}  
    clock_t end = clock();
    time_spent += (double)(end - begin)/CLOCKS_PER_SEC;
    printf("time of execution of program is:%lf",time_spent);
	
}		       
