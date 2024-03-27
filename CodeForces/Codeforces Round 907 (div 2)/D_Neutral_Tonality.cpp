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
     vl v(n);
     vl b(m);
     inp(v);
     inp(b);
     
     sort(all(b),greater<ll>());
     ll ind=0;
     vl ans;
 
     for(int i=0;i<n;i++){
          while(ind<m and b[ind]>=v[i]){ 
               ans.pb(b[ind]);
               ind++;
          }
          ans.pb(v[i]);
     }
          
     while(ind<m){
          ans.pb(b[ind]);
          ind++;
     }
          
     for(auto i:ans) cout<<i<<" ";
     cout<<endl;
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