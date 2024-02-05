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

ll digit(ll n){
    set<ll>st;
    while(n){
        st.insert(n%10);
        n/=10;
    }
    ll ans=0;
    for(auto i:st){
        ans|=(1<<i);
    }
    return ans;
}

void dk(){
     ll n;
     cin>>n;
     assert(n>=1 and n<=1e5);
     map<ll,ll>mp;
     vl v(n);
     inp(v);
     vl col(n);
     inp(col);
     ll ans=0;
     rep(i,0,n){
        v[i]=digit(v[i]);
        // ans|=(1<<(col[i]+10));
        // assert(v[i]>=1 and v[i]<=1e18);
        // assert(col[i]>=0 and col[i]<=3);
        // mp[ans]++;
     }
     rep(i,0,n){
        rep(j,i+1,n){
            if((v[i]&v[j])==0 and col[i]!=col[j]){
                ans++;
            }
        }
     }
    //  ll ans=0;
    //  for(auto [a1,a2]:mp){
    //     for(auto [a3,a4]:mp){
    //         if((a1&a3)==0){
    //             ans+=a2*a4;
    //         }
    //     }
    //  }
    cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    // cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   