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

ll n;
vl v;

bool check(ll sum){
     ll cur=0;
     for(auto i:v){
          ll x=sum/i;
          while(x*i<sum) x++;
          cur+=x;
     }
     return cur<sum;
}

void dk(){
     cin>>n;
     v.assign(n,0);
     inp(v);
     ll l=1,r=1e9,ans=1e9;
     if(check(r)==0){
          cout<<-1<<endl;
          return;
     }
     vl ret;
     for(auto i:v){
          ll x=ans/i;
          while(x*i<ans)x++;
          ret.pb(x);
     }
     for(auto i:ret){
          cout<<i<<" ";
     }
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