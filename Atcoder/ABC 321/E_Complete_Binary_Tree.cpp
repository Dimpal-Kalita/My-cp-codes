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



ll recur(ll n,ll x,ll k,ll extra){
     if(x==0) return 0;
     if(k==0) return 1;

     ll branchlow=x*(1ll<<k);
     ll branchhigh=branchlow+(1ll<<k)-1;
     ll val=max(0LL,min(n,branchhigh)-branchlow+1);
     if(extra){
          val=max(0LL,val-(1ll<<(k-1)));
     }
     ll ans=val;
     // cout<<x<<" "<<branchhigh<<" "<<branchlow<<" "<<val<<" "<<ans<<" "<<extra<<endl;
     return ans+recur(n,x/2,k-1,1); 

}

void dk(){
     ll n,x,k;
     cin>>n>>x>>k;
     
     cout<<recur(n,x,k,0)<<endl;
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