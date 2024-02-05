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


void dk(){
     ll n;
     cin>>n;
     vector<vector<ll>> adj(n+1);
     for(ll i=0;i<n-1;i++){
         ll u,v;
         cin>>u>>v;
         adj[u].pb(v);
         adj[v].pb(u);
     }
     vector<ll> dp(n+1,0);
     set<pll>st;

     function<void(vl)> all_sum=[&](vl v)->void{
           bitset<6000>bt;
           bt[0]=1;
           for(auto &i:v){
               bt|=bt<<i;
           }
           for(ll i=1;i<n-1;i++){
               if(bt[i]){
                   st.insert({i,n-i-1});
                   st.insert({n-i-1,i});
               }
           }
     };

     function<ll(ll,ll)> dfs=[&](ll node,ll par){
         ll ans=1;
         vl v;
         for(auto &i:adj[node]){
             if(i!=par){
                 ans+=dfs(i,node);
                 v.pb(dp[i]);   
             }
         }
         all_sum(v);
         return dp[node]=ans;
     };
     dfs(1,0);
     cout<<st.size()<<endl;
     for(auto &i:st){
          cout<<i.F<<" "<<i.S<<endl;
     }
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