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
     ll n,k;
     cin>>n>>k;
     vector<vl>adj(n+1);
     rep(i,0,n-1){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     
     auto check=[&](ll mid)->bool{
          ll cut=0;
         function<ll(ll,ll)> dfs=[&](ll node,ll par)->ll{
               ll ct=1;
               for(auto child:adj[node]){
                    if(child==par) continue;
                    ct+=dfs(child,node);
               }
               if(ct>=mid and cut<k and par!=-1){
                    cut++;
                    ct=0;
               }
               return ct;
         }; 
         ll ct=dfs(1,-1);
         return (ct>=mid and cut==k);
     };
     
     ll l=0,r=n+1,ans=0;
     while(l<r){
          ll mid=(l+r)/2;
          if(check(mid)){
               l=mid+1;
               ans=mid;
          }
          else r=mid;
     } 
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