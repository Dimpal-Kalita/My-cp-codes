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


bool all_equal(vl &v){
     ll x=v[0];
     for(auto i:v) if(i!=x) return 0;
     return 1;
}

void dk(){

     ll n;
     cin>>n;
     vl v(n);
     inp(v);

     if(all_equal(v)){
          cout<<"-1"<<endl;
          return;
     }
 
     vl index;
     ll ans=n-1;
     for(int i=0;i<n;i++){
          if(v[0]!=v[i]) index.pb(i);
     }
     for(int i=1;i<index.size();i++){
          ans=min(ans,index[i]-index[i-1]-1);
     }
     ans=min(ans,index.front());
     ans=min(ans,n-index.back()-1);
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