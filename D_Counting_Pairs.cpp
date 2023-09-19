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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
     tree_order_statistics_node_update>;

void dk(){
     ll n;
     cin>>n;
     vector<pll>vp(n);
     rep(i,0,n){
          cin>>vp[i].F;
     }
     rep(i,0,n){
          cin>>vp[i].S;
     }
     sort(all(vp));
     ll Q;
     cin>>Q;
     vector<pair<pll,ll>>q;
     rep(i,0,Q){
          ll x,y;
          cin>>x>>y;
          q.pb({{x,y},i});
     } 
     sort(all(q));
     int ind=0;
     Tree<ll>tree;
     vector<ll>ans(Q);
     for(auto it:q){
          while(ind<n and vp[ind]<=it.F){
               tree.insert(vp[ind].S);
               ind++;
          }
          ans[it.S]=tree.order_of_key(it.F.S+1);
     }
     for(auto it:ans){
          cout<<it<<endl;
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