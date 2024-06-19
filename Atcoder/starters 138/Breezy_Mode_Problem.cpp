#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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
     ll n,q;
     cin>>n>>q;
     vl v(n);
     map<ll,ll>mp;
     for(int i=0;i<n;i++){
          cin>>v[i];
          mp[v[i]]++;
     }
     ll ans=0;
     for(auto x: mp) ans+=(x.S*(x.S+1))/2;
     while(q--){
          ll p,x;
          cin>>p>>x;
          p--;
          ans-=(mp[v[p]]);
          mp[v[p]]--;
          v[p]=x;
          mp[v[p]]++;
          ans+=(mp[v[p]]);
          cout<<ans<<endl;
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