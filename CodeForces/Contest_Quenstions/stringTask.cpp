#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
ll n;
string s;
string s2;
cin>>s;
n=s.length();
for (ll i = 0; i < n; i++)
{ if(s[i]<='Z' && s[i]>='A')
    s[i]=s[i]+32;
}
for (ll i = 0; i < n; i++)
{
    if(s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='a'&& s[i]!='e' && s[i]!='y')
    {
cout<<"."<<s[i];
    }
    
}
cout<<endl;
return 0;
}