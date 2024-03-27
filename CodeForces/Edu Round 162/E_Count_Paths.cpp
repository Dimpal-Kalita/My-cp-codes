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


#define mpl map<ll,ll>

void dk(){
     ll n;
     cin>>n;
     vl v(n+1);
     rep(i,1,n+1){
        cin>>v[i];
     } 
     vector<vl>adj(n+1);
     rep(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
     }
     ll ans=0;
     function<mpl(ll node, ll par)> dfs = [&](ll node, ll par){
        mpl mp;
        for(auto x: adj[node]){
            if(x==par) continue;
            mpl temp = dfs(x,node);
            ans+=temp[v[node]];
            temp.erase(v[node]);
            if(temp.size()>mp.size()){
                  swap(temp,mp);
            }
            for(auto y: temp){
                ans+=y.S*mp[y.F];
                mp[y.F]+=y.S;
            }
        }
        mp[v[node]]=1;
        return mp;
     };
   dfs(1,0);
   cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   