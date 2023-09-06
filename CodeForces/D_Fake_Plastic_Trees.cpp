/**
 * 
 * author: Dimpal Kalita
 * 
 */

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


ll n;
vector<pll> v;
vector<vl>adj;
ll ans;

ll dfs(ll node, ll par){
    ll mn=0;
    for(auto x: adj[node]){
        if(x!=par){
            mn+=dfs(x,node);
        }
    }
    mn=min(mn,v[node].S);
    if(mn<v[node].F){
      ans++;
      mn=v[node].S;
    }
    return mn;
}



void dk(){
    cin>>n;
    ans=0;
    v.resize(n+1);
    adj.assign(n+1,{});
    rep(i,0,n-1){
      ll x=i+2,y;
      cin>>y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    rep(i,1,n+1){
        cin>>v[i].F>>v[i].S;
    }
    dfs(1,0);
    cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}