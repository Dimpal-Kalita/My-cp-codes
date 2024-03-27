#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n;
     cin>>n;
     string s;
     cin>>s; 
     map<char,vector<int>>mp;
     for(int i=0;i<n;i++){
          mp[s[i]].pb(i);
     }
     ll q;
     cin>>q;
     while(q--){
          char u,v;
          cin>>u>>v;
          if(u==v) continue;
          if(mp[u].size()>mp[v].size()){
               swap(mp[u],mp[v]);
          }
          for(auto it:mp[u]){
               mp[v].pb(it);
          }
          mp[u].clear();
     }
     vector<char> ans(n);
     for(auto it:mp){
          for(auto x:it.S){
               ans[x]=it.first;
          }
     }
     for(int i=0;i<n;i++){
          cout<<ans[i];
     }
     cout<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   