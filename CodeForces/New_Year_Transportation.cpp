#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
ll n,t;
cin>>n>>t;
ll arr[n];
for (ll i = 0; i < n-1; i++)
{
    cin>>arr[i];
}
ll cur=1;
for (; cur<n;)
{
    cur=cur+arr[cur-1];
    if(cur==t)
    {
        cout<<"YES"<<endl;
        return 0;
    }
}
cout<<"NO"<<endl;
return 0;
}