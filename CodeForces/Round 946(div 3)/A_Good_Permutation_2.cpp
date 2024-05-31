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
      vl v(m);
      map<ll,ll>mp;
      for(auto &it:v){
          cin>>it;
          if(it==1 or it==n){
               cout<<"-1"<<endl;
               return;
          }
          mp[it]++;
      }
      vector<ll> ans(n+1);
      rep(i,1,n+1) ans[i]=i;
      for(auto it:mp){
          swap(ans[it.F],ans[it.F+1]);
      }
      rep(i,1,n+1) cout<<ans[i]<<" ";
      cout<<endl;
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