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
     vector<vl>adj(n+1);
     rep(i,2,n+1){
          ll x;
          cin>>x;
          adj[x].pb(i);
          adj[i].pb(x);
     }
     string s;
     cin>>s;
     ll ans=0;
     function<pll(ll,ll)> dfs=[&](ll u,ll p){
          ll sleep=0,party=0;
          for(auto v:adj[u]){
               if(v==p) continue;
               auto [sc,py]=dfs(v,u);
               if(s[u-1]=='S' and py){
                    ans++;
                    py=0;
               }
               if(s[u-1]=='P' and sc){
                    ans++;
                    sc=0;
               }
               sleep+=(sc>0);
               party+=(py>0);
          }
          if(s[u-1]=='C'){
               if(sleep==party){
                    ans+=sleep;
               }else if(sleep>party){
                    ans+=party;
                    s[u-1]='S';
                    party=0;
               }else{
                    s[u-1]='P';
                    ans+=sleep;
                    sleep=0;
               }
          }
          sleep=(s[u-1]=='S');
          party=(s[u-1]=='P');
          return make_pair(sleep,party);
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