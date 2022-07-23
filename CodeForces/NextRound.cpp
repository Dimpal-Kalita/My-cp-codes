#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll count=0;
    ll ss=0;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i]<=0)
        {
            ss++;
        }
    }
    for(ll i=0; i<n; i++)
    {
        if(arr[i]>=arr[k-1] && arr[i]>0)
        {
            count++;
        }
    }
if(ss==n)
cout<<0<<endl;
else 
cout<<count<<endl;
    

 return 0;
}