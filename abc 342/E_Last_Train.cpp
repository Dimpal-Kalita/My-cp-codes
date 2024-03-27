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
     ll n,m;
     cin>>n>>m;
     vector<set<ll>>adj(n+1);
     map<pll,vector<array<ll,4>>>mp;
     for(int i=0;i<m;i++){
          ll a,d,k,c,u,v;
          cin>>a>>d>>k>>c>>u>>v;
          adj[v].insert(u);
          mp[{v,u}].pb({a,d,k,c});
     }
     vl ans(n+1,-1);
     priority_queue<pll>pq;

     pq.push({n,LONG_MAX});
     
     while(!pq.empty()){
          auto [node,mx]=pq.top();
          pq.pop();
          for(auto v:adj[node]){
               ll mx2=-1
               for(auto it:mp[{node,v}]){
                    auto [a,d,k,c]=it;
                    ll temp=mx-c;
                    ll tempk=(temp-a)/d;
                    if(tempk<0) continue;
                    tempk=min(tempk,k-1);
                    mx2=max(mx2,min(temp,a+tempk*d));
               }
               if(mx2==-1) continue;
               if(ans[v]<mx2)
                    pq.push({v,ans[v]=mx2});
          }
     }

     for(int i=1;i<n;i++){
          if(ans[i]==-1){
               cout<<"Unreachable"<<endl;
          }else{
               cout<<ans[i]<<endl;
          }
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