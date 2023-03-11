// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



ll expo(ll a, ll b, ll mod=md) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}




void dk(){
     ll n;
     cin>>n;
     vector<vector<ll>> adj(n+1);
     for(int i=0;i<n-1;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
     }
     ll sum=n;
     auto dfs=[&](auto dfs,ll u, ll p)->ll{
        ll ans=0;
        for(auto v:adj[u]){
            if(v!=p){
                ans=max(ans, dfs(dfs,v, u));
            }
        }
        sum=(sum+ans)%md;
        return ans+1;
     };
     ll ans= dfs(dfs,1, 0);
     cout<<(sum*expo(2,n-1))%md<<endl;
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