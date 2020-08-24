#include <bits/stdc++.h> 
using namespace std; 
  
int binarySearch(int arr[], int low, int high)  
{  
    if(high >= low)  
    {  
        int mid = (low + high)/2; 
        if(mid  == arr[mid])  
            return mid ;  
        if(mid > arr[mid])  
            return binarySearch(arr, (mid + 1), high);  
        else
            return binarySearch(arr, low, (mid -1));  
    }  
    return -1;
    
}  
  
int main()  
{  
    int n;
    cout<<"enter size of an array:";
    cin>>n;
    int a[n+1];
    a[0]=0;
    cout<<"enter elements of an array:"<<endl;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    cout<<"Fixed index is "<< binarySearch(a, 1, n);  
    return 0;  
}  
