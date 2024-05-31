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


vl v;

void gen(ll num){
     ll x=num*10;
     if(x<=1e5){
          v.pb(x);
          gen(x);
     }
     x=num*10+1;
     if(x<=1e5){
          v.pb(x);
          gen(x);
     }
}

void dk(){
     ll n;
     cin>>n;
     for(auto i:v){
          while(n%i==0){
               n/=i;
          }
     }
     cout<<(n==1?"YES":"NO")<<endl;
}



int main()
{ 
    fast_io;
    gen(1);
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   