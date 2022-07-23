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
           cout<<min(x,y,d)<<endl;
        }



    }

 return 0;
}