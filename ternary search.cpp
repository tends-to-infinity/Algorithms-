#include<bits/stdc++.h>
using namespace std;
int ternarysearch(int a[],int n,int ele,int l,int h)
{
	if(l<=h)
	{
	
	int m1,m2;
	m1=l+(h-l)/3;
	m2=h-(h-l)/3;
	if(a[m1]==ele)
	return m1;
	if(a[m2]==ele)
	return m2;
	if(ele<a[m1])
     	return ternarysearch(a,n,ele,l,m1-1);
   else if(ele>a[m2])
	 return	 ternarysearch(a,n,ele,m2+1,h);
	 else
	 return	 ternarysearch(a,n,ele,m1+1,m2-1);
  }
return -1; 
}
int main()
{
	int n;
	cout<<"Enter size:";
	cin>>n;
	int a[n],ele;
	cout<<"Enter elemnts of an array:\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<"enter element to be search:";
	cin>>ele;
    int l=0;
    int h=n-1;
	int x=ternarysearch(a,n,ele,l,h);
	if(x==-1)
	cout<<"not present";
	else
	cout<<"present";
}
