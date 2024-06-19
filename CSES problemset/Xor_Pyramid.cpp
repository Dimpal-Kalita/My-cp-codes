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




vl calc(ll n){
     vl cnt(n);
     for(int i=1;i<=n;i++){
          ll x=i;
          cnt[i]+=cnt[i-1];
          while(x%2==0){
               x/=2;
               cnt[i]++;
          }
     }
     return cnt;
}

const int N=2e5+2;

vl cnt=calc(N);

ll nCr(ll n,ll r){
     ll a=cnt[n];
     ll b=cnt[r];
     ll c=cnt[n-r];
     a-=(b+c);
     return a;
}

void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     ll ans=0;
     for(int i=0;i<n;i++){
          ll x=nCr(n-1,i);
          if(!x){
               ans^=v[i];
          }
     }
     
     cout<<ans<<endl;
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