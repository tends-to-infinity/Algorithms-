#include <iostream> 
using namespace std; 

void merge(int l, int r, int* output,int n) 
{ 
	
	int l_in = l * n, r_in = ((l + r) / 2 + 1) * n; 
	int l_c = ((l + r) / 2 - l + 1) * n; 
	int r_c = (r - (l + r) / 2) * n; 

	int l_arr[l_c], r_arr[r_c];  
	for (int i = 0; i < l_c; i++) 
		l_arr[i] = output[l_in + i]; 

	for (int i = 0; i < r_c; i++) 
		r_arr[i] = output[r_in + i]; 


	int l_curr = 0, r_curr = 0; 
	int in = l_in; 

	
	while (l_curr + r_curr < l_c + r_c) { 
		if (r_curr == r_c || (l_curr != l_c && 
			l_arr[l_curr] < r_arr[r_curr])) 
			output[in] = l_arr[l_curr], l_curr++, in++; 
		else
			output[in] = r_arr[r_curr], r_curr++, in++; 
	} 
} 

void divide(int l, int r, int* output, 
			int arr[][100],int n) 
{ 
	if (l == r) { 

		for (int i = 0; i < n; i++) 
			output[l * n + i] = arr[l][i]; 

		return; 
	} 

	divide(l, (l + r) / 2, output, arr,n); 

	divide((l + r) / 2 + 1, r, output, arr,n); 


	merge(l, r, output,n); 
} 


int main() 
{   
    int k,n;
	cout<<"Enter no. of arrays :";
	cin>>k;
	
	cout<<"Enter size of array: "; 
	cin>>n;

	int a[100][100];
	
	cout<<"Enter k arrays :";
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>a[i][j];
     int s=n*k;
    int output[s];

	divide(0, k - 1, output, a,n); 

	for (int i = 0; i < n * k; i++) 
		cout << output[i] << " "; 

	return 0; 
} 

