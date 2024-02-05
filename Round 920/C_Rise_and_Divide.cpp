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



ll dp[10000000];

ll recur(ll n){
     if(dp[n]!=0) return dp[n];
     ll &ans=dp[n];
     while(n>1){
          if(n%2) n=n*3+1;
          else n/=2;
          ans++;
     }
     return ans;
}
void dk(){
     ll n;
     cin>>n;
     ll alice=0,bob=0,draw=0;
     while(n--){
          ll a,b;
          cin>>a>>b;
          if(recur(a)<recur(b)) alice++;
          else if(recur(a)>recur(b)) bob++;
          else draw++;
     }
     cout<<alice<<" "<<bob<<" "<<draw<<endl;
}


int main()
{ 
    fast_io;
    memset(dp,0,sizeof(dp));
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   