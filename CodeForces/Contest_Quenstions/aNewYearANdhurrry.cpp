#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
    ll n,k,b=0;
    cin>>n>>k;
    ll sum=0;
    ll a=240-k;
    for (ll i=0; i <n; i++)
    { 
        sum=sum+ 5*(i+1);
        if(sum>a)
        {
            break;
        }
        b++;
    }
    cout<<b<<endl;
    

 return 0;
}