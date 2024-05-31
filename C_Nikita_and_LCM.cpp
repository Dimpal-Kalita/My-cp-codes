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
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     ll l=1;
     sort(all(v));
     ll mx=v.back();
     map<ll,ll>mp;
     for(auto i:v){
          l=lcm(l,i);
          mp[i]++;
          if(l>mx or mx%l){
               cout<<n<<endl;
               return;
          }
     }
     set<ll>st;
     for(ll i=1;i*i<=mx;i++){
          if(l%i==0){
               if(!mp.count(i)) st.insert(i);
               if(!mp.count(l/i)) st.insert(l/i);
          }
     }
     ll ans=0;
     for(auto i:st){
          ll cnt=0;
          ll l=1;
          // cout<<i<<" ->";
          for(auto j:v){
               if(i%j==0){
                    l=lcm(l,j);
                    cnt++;
                    // cout<<j<<" ";
               }
          }
          // cout<<endl;
          if(l==i) ans=max(ans,cnt);
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