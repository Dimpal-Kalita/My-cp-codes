#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
    ll n, m, a, b, c;
    cin>>n>>m>>a;
 
if(n%a==0 || m%a==0)
{
    if(n%a==0 && m%a==0)
    {
        cout<<(n/a)*(m/a)<<endl;
    }
    else if(n%a!=0 && m%a==0)
    {
        cout<<(n/a+1)*(m/a)<<endl;
    }  
    else if( n%a==0 && m%a!=0)
    cout<<(n/a)*(m/a+1)<<endl;
}
else
{
    cout<<(n/a+1)*(m/a+1)<<endl;
}
       


 return 0;
}