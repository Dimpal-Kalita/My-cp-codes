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

// 6,2
// 4,4
void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     map<ll,ll>mp;
     ll ans=0;
     for(auto x:v){
          if(x==4) ans+=mp[4];
          if(x==2) ans+=mp[6];
          mp[x]++;
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