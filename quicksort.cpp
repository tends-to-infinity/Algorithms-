#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int start,int end)
{
	int pivot=a[end];
	int pindex=start;
	for(int i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			int t=a[i];
			a[i]=a[pindex];
			a[pindex]=t;
			pindex=pindex+1;
		}
	}
	int x=a[pindex];
	a[pindex]=a[end];
	a[end]=x;
	return pindex;
}
quicksort(int a[],int start,int end)
{  int pindex;
   if(start<end)
   {
 pindex=partition(a,start,end);
  quicksort(a,start,pindex-1);
 quicksort(a,pindex+1,end);
}
	
}
int main()
{
	int n;
	cout<<"Enter size:";
	cin>>n;
	int a[n];
	cout<<"Enter elements of an array:\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	quicksort(a,0,n-1);
	cout<<"Array after sorting is:\n";
	for(int i=0;i<n;i++)
         
		 	{
		       cout<<a[i]<<" ";
		
           	}
           	return 0;
}
