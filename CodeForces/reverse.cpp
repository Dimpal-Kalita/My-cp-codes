#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
ll t;
cin>>t;
while(t--)
{
ll n, final, initial;
cin>>n;
ll arr[n];
ll brr[n];
bool dimpal=true;
for (ll i = 0; i < n; i++)
{
    cin>>arr[i];
}
for (ll i = 0; i < n; i++)
{
   if(arr[i]!=i+1)
   final=i;
  dimpal=false;
  break; 
}
for (ll i = 0; i < n; i++)
{
    if(arr[i]==final)
    initial=i;
    break;
}
if(dimpal)
{
    for (ll i = 0; i < n; i++)
    {
     cout<<arr[i]<<" ";
    }
    
}
else{
for (ll i = 0; i < initial; i++)
{
cout<<arr[i]<<" ";
}
for (ll i = initial; i < final; i++)
{
    cout<<arr[i]<<" ";
}
for (ll i = final; i < n; i++)
{
    cout<<arr[i]<<" ";
}


}
}
return 0;
}