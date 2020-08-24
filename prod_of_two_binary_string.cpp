#include<iostream> 
#include<stdio.h> 
using namespace std; 
  
int equal_len(string &s1, string &s2) 
{ 
    int l1 = s1.size(); 
    int l2 = s2.size(); 
    if (l1 < l2) 
    { 
        for (int i = 0 ; i < l2 - l1 ; i++) 
            s1 = '0' + s1; 
        return l2; 
    } 
    else if (l1 > l2) 
    { 
        for (int i = 0 ; i < l1 - l2 ; i++) 
            s2 = '0' + s2; 
    } 
    return l1; 
} 
  
string add_string( string f, string s) 
{ 
    string res;   
  
    int l = equal_len(f,s); 
    int c = 0;  
   
    for (int i = l-1 ; i >= 0 ; i--) 
    { 
        int fBit = f.at(i) - '0'; 
        int sBit = s.at(i) - '0'; 
  
        int sum = (fBit ^ sBit ^ c)+'0'; 
  
        res = (char)sum + res; 
  
        c = (fBit&sBit) | (sBit&c) | (fBit&c); 
    } 
   
    if (c) 
	{
	  res = '1' + res; 
    }
  return res; 
} 
  
int mul_SingleBit(string a, string b) 
          { 
               return (a[0] - '0')*(b[0] - '0'); 
		 } 
  
long int multiply(string X, string Y) 
{ 
    
    int n = equal_len(X, Y); 
   
    if (n == 0) return 0; 
    if (n == 1) return mul_SingleBit(X, Y); 
  
    int fh = n/2;   
    int sh = (n-fh); 

    string Xl = X.substr(0, fh); 
    string Xr = X.substr(fh, sh); 
  
    
    string Yl = Y.substr(0, fh); 
    string Yr = Y.substr(fh, sh); 
  
    
    long int P1 = multiply(Xl, Yl); 
    long int P2 = multiply(Xr, Yr); 
    long int P3 = multiply(add_string(Xl, Xr), add_string(Yl, Yr)); 
   
    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
} 
  
int main() 
{    
    string str1, str2;
    cout<<"Enter two binary strings: "<<endl;
    cin>>str1>>str2;
    cout<<"multiplication is:"<<multiply(str1 , str2);
    
}
