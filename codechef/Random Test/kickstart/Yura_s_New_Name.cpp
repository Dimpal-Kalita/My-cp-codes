// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using pii = pair<int,int>;
using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using vi  = vector<int>;



void dk(){
    string s;
    cin>>s;
    ll n=s.length();
    ll ct=0;
    if(s[0]!='^') ct++;
    for(int i=0;i<n;i++){
        if(s[i]=='_'){
            if(i+1<n and s[i+1]!='^') ct++;
            else if(i+1==n) ct++;
        }
    }
    if(s[0]=='^' and s.length()==1) ct++;
    cout<<ct<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}