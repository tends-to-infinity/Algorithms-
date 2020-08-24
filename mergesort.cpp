#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int mid, int right) 
{ 
    int i,j,k; 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
  
  int Left[n1], Right[n2]; 
  

    for (i = 0; i < n1; i++) 
        Left[i] = a[left + i]; 
    for (j = 0; j < n2; j++) 
        Right[j] = a[mid + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) 
    { 
        if (Left[i] <= Right[j]) 
        { 
            a[k] = Left[i]; 
            i++; 
        } 
        else
        { 
            a[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < n1) 
    { 
        a[k] = Left[i]; 
        i++; 
        k++; 
    } 
  

    while (j < n2) 
    { 
        a[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int a[], int left, int right) 
{ 
    if(left<right)
    { 
        int mid=left+(right-left)/2; 
      mergeSort(a, left, mid); 
        mergeSort(a, mid+1, right); 
  
        merge(a, left, mid, right); 
    } 
} 

int main() 
{ 
    int n;
     cout<<"Enter size of an array:";
    cin>>n;
    int a[n];
    
    cout<<"Enter elements of an array:\n";
    
    for(int i=0;i<n;i++)
    cin>>a[i]; 
    
  /*srand(time(NULL));
    int m=1000;
     
     int a[m];
    for(int i=0;i<m;i++)
      a[i]=rand()%m;*/
  
    mergeSort(a, 0, n- 1); 
  
    cout<<"Array after sorting is:\n";
    
	for(int i=0;i<n;i++)
	cout<<a[i]<<" "; 
    return 0; 
} 
