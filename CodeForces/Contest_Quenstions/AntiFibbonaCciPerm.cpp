#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
//main function
int main()
{
int t;
cin>>t;
while(t--)
{
 int n;
 cin>>n;
 int k=n;
 int a[n];
 for (int i = 0; i < k; i++)
 {
     a[i]=n-i;
 }
 if(n==3)
 {
  
     cout<<a[2]<<" "<<a[0]<<" "<<a[1]<<endl;
     cout<<a[0]<<" "<<a[2]<<" "<<a[1]<<endl;
      cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
     
     
 }
 else{
 for (int i = 0; i < n; i++)
 {
      for (int j = k-i; j <k; j++)
     {
        cout<<a[j]<<" ";
     }
     for (int num = 0; num<k-i; num++)
     {
         cout<<a[num]<<" ";
     }
     cout<<endl;     
 }
 }
}
    return 0;
}