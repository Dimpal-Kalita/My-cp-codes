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
using Tree = tree<T, null_type, greater<T>, rb_tree_tag,
     tree_order_statistics_node_update>;

void dk(){
     ll n;
     cin>>n;
     vector<pll>vp(n);
     for(auto &x:vp){
          cin>>x.F>>x.S;
     }
     sort(all(vp));
     ll ans=0,x=0;
     Tree<ll>t;
     for(int i=0;i<n;i++){
          ans+=t.order_of_key(vp[i].S);
          t.insert(vp[i].S);
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