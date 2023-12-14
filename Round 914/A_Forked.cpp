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
     ll a,b;
     cin>>a>>b;
     ll xk,yk;
     cin>>xk>>yk;
     ll xq,yq;
     cin>>xq>>yq; 
     vector<pll> knight={{-b,-a},{-b,a},{b,-a},{b,a},{-a,-b},{-a,b},{a,-b},{a,b}};
     vector<pll>vp;
     for(auto x:knight){
          vp.pb({xk+x.F,yk+x.S});
     }
     sort(all(vp));
     ll ans=0;
     set<pll>st;
     for(auto it:knight){
          ll x=xq+it.F,y=yq+it.S;
          if(binary_search(all(vp),make_pair(x,y))){
               st.insert({x,y});
          }
     }
     cout<<st.size()<<endl;
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