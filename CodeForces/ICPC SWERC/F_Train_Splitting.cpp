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




void dk(){
     ll n,m;
     cin>>n>>m;
     vector<set<ll>> adj(n+1); 
     vector<pll> vp;
     for(int i=0;i<m;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        vp.pb({u,v});
     }
     vector<ll>ans(m, 0);
     
     
     bool flag=0;
     for(int i=1;i<=n;i++){

        if(adj[i].size()<n-1){
            
            for(auto it:adj[i]){

                pll pp1={i,it};
                pll pp2={it,i};

                for(int j=0;j<m;j++){
                    if(ans[j]==0 && (vp[j]==pp1|| vp[j]==pp2)){
                        ans[j]=1;
                    }
                }

            }

            flag=1;
            break;
        }
     }
     
     if(flag){
        cout<<2<<endl;
        for(auto it:ans){
            cout<<(it?it:2)<<" ";
        }
        cout<<endl;
        return;
     }


     int ct=0, val=1;
     pll pp1={1,2};
     pll pp2={2,1};

     for(int j=0;j<m;j++){
        if(ans[j]==0 && (vp[j]==pp1|| vp[j]==pp2)){
            ans[j]=1;
        }
     }

     for(auto it:adj[1]){
        pll pp1={1,it};
        pll pp2={it,1};

        for(int j=0;j<m;j++){
            if(ans[j]==0 && (vp[j]==pp1|| vp[j]==pp2)){
                ans[j]=2;
            }
        }

     }


     cout<<3<<endl;
     for(auto it:ans){
        cout<<(it?it:3)<<" ";
     }
     cout<<endl;




     


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