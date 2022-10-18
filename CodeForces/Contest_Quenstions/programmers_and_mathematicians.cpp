#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    { 
        ll x, y;
        cin>>x>>y;
        ll d=(x+y)/4;
        if(x==y)
        cout<<d<<endl;
        else
        {
          ll e=min(x,y);
          ll f=min(e, d);
          cout<<f<<endl; 
        }



    }

 return 0;
}